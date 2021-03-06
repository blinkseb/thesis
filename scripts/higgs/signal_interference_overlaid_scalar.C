#define MTOP 172.5
#define ALPHAS 0.118
#define GF 1.16639000E-05

// par[0]=m

Double_t WH(Double_t* x, Double_t* par)
{
  Double_t xx = x[0]*x[0];
  Double_t beta = TMath::Sqrt(1-4*MTOP*MTOP/xx);
  return 3*GF*MTOP*MTOP*par[0]*pow(beta,3)/(4*TMath::Pi()*TMath::Sqrt(2));
}

Double_t BW(Double_t* x, Double_t* par)
{
  Double_t xx = x[0]*x[0];
  Double_t value = 1/(pow(xx-par[0]*par[0],2)+pow(par[0]*WH(x,par),2));
  return value;
}

Double_t Signal(Double_t* x, Double_t* par)
{
  Double_t xx = x[0]*x[0];
  Double_t beta = TMath::Sqrt(1-4*MTOP*MTOP/xx);
  Double_t y_t= TMath::Log((1+beta)/(1-beta));
  
  Double_t yt2 = y_t*y_t;
  Double_t beta2 = beta*beta;
  Double_t pi2 = TMath::Pi() * TMath::Pi();

  Double_t constant= 3*pow(ALPHAS,2)*pow(GF,2)*pow(MTOP,6)/( 2048*pow(TMath::Pi(),3) );
  Double_t value = constant * pow(beta,3) * ( 16 + 8*beta2*(pi2-yt2) + beta2*beta2*pow(yt2+pi2,2) ) * BW(x,par);
  return value;

}

Double_t Interference(Double_t* x, Double_t *par)
 // par = m, w, coupl
{
  Double_t xx = x[0]*x[0];
  Double_t MH = par[0];
  Double_t beta = TMath::Sqrt(1-4*MTOP*MTOP/xx);
  Double_t y_t= TMath::Log((1+beta)/(1-beta));

  Double_t yt2 = y_t*y_t;
  Double_t beta2 = beta*beta;
  Double_t pi2 = TMath::Pi() * TMath::Pi();

  Double_t constant= -1. * pow(ALPHAS,2)*GF*pow(MTOP,4)/( 32*TMath::Pi()*TMath::Sqrt(2) );
  //Double_t value = constant * beta2 * y_t / xx * ( (xx-MH*MH)*(4+beta2*(pi2-yt2)) + 2*TMath::Pi()*beta2*MH*WH*yt ) * BW(x[0],par[0],par[1],par[2]);
  Double_t value = constant * beta2 * y_t / xx * ( (xx-MH*MH)*(4+beta2*(pi2-yt2)) + 2*TMath::Pi()*beta2*MH*WH(x,par)*y_t ) * BW(x,par);

  return value; 
}

Double_t Somme(Double_t* x, Double_t *par)
{
   return Signal(x,par)+Interference(x,par);
}

void wilenbrock(double m)
{
  TCanvas* c = new TCanvas();
  c->Divide(2,2);
  c->cd(1);
  TF1* func_sig = new TF1("Signal",Signal,350,1000,1);
  func_sig->SetParameter(0,m);
  func_sig->Draw();

  c->cd(2);
  TF1* func_inter = new TF1("Interference",Interference,350,1000,1);
  func_inter->SetParameter(0,m);
  func_inter->Draw();
  
  c->cd(3);
  TF1* func_all = new TF1("Somme",Somme,350,1000,1);
  func_all->SetParameter(0,m);
  func_all->Draw();

  c->cd(4);
  TF1* func_wh = new TF1("WH",WH,350,1000,1);
  func_wh->SetParameter(0,m);
  func_wh->Draw();
}

#include "tdrstyle.C"

void signal_interference_overlaid_scalar()
{

  setTDRStyle();

  TCanvas* c = new TCanvas();
  TF1* func = new TF1("Signal + Interferences",Signal,350,900,1);
  func->SetMinimum(-6e-9);
  //func->GetXaxis()->SetTitle("m_{t#bar{t}}");
  double m=500;
  func->SetParameter(0,m);
  func->SetLineColor(TColor::GetColor("#8A9B0F"));
  func->SetLineWidth(2);
  func->SetNpx(1000);
  func->Draw();
  func->GetXaxis()->SetTitle("m_{t#bar{t}}");
  TF1* func2 = new TF1("Signal + Interferences",Interference,350,900,1);
  func2->SetParameter(0,m);
  func2->SetLineColor(TColor::GetColor("#E97F02"));
  func2->SetLineWidth(2);
  func2->SetNpx(1000);
  func2->Draw("SAME");
  TF1* func3 = new TF1("Signal + Interferences",Somme,350,900,1);
  func3->SetParameter(0,m);
  func3->SetLineColor(TColor::GetColor("#53777A"));
  func3->SetLineWidth(2);
  func3->SetLineStyle(kDashed);
  func3->SetNpx(1000);
  func3->Draw("SAME");

  TLegend l(0.65 - 0.1, 0.75 - 0.5, 0.9 - 0.1, 0.9 - 0.5);
  l.SetBorderSize(0);
  l.SetFillColor(0);
  l.SetTextFont(42);
  l.SetTextSize(0.033);
  l.AddEntry(func, "Signal", "L");
  l.AddEntry(func2, "Interference", "L");
  l.AddEntry(func3, "Signal + interference", "L");
  l.Draw("same");

  c->SaveAs("scalar_sig_int.pdf");
}
