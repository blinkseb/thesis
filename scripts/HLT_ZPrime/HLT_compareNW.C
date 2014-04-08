{

#include "tdrstyle.C"

  setTDRStyle();

  TFile f1("MTT_Histos_Zprime_750_Narrow_2012_v1_semimu.root");
  TFile f2("MTT_Histos_Zprime_750_Large_2012_v1_semimu.root");
  TFile f3("MTT_Histos_Zprime_750_Narrow_2012_v1_semie.root");
  TFile f4("MTT_Histos_Zprime_750_Large_2012_v1_semie.root");

  //TString histoname = "hLeptonPt";
  //TString histoname = "h1stjetpt";
  //TString histoname = "h2ndjetpt";
  //TString histoname = "h3rdjetpt";
  TString histoname = "h4thjetpt";
  //  TString histoname="selected_events_trigger";
// hLeptonPt	
// h1stjetpt	
// h2ndjetpt	
// h3rdjetpt	
// h4thjetpt

  TH1F *h1 = (TH1F*) f1.Get(histoname);
  TH1F *h2 = (TH1F*) f2.Get(histoname);
  TH1F *h3 = (TH1F*) f3.Get(histoname);
  TH1F *h4 = (TH1F*) f4.Get(histoname);

  h1->SetLineColor(TColor::GetColor("#556270"));
  h2->SetLineColor(TColor::GetColor("#C44D58"));
  h3->SetLineColor(TColor::GetColor("#556270"));
  h4->SetLineColor(TColor::GetColor("#C44D58"));


  h1->SetMarkerColor(h1->GetLineColor());
  h2->SetMarkerColor(h2->GetLineColor());
  h3->SetMarkerColor(h3->GetLineColor());
  h4->SetMarkerColor(h4->GetLineColor());

  h1->SetMarkerStyle(20);
  h2->SetMarkerStyle(21);
  h3->SetMarkerStyle(20);
  h4->SetMarkerStyle(21);

  h1->SetMarkerSize(1);
  h2->SetMarkerSize(1);
  h3->SetMarkerSize(1);
  h4->SetMarkerSize(1);

  h1->SetLineWidth(1);
  h2->SetLineWidth(1);
  h3->SetLineWidth(1);
  h4->SetLineWidth(1);

  h1->Rebin(2);
  h2->Rebin(2);
  h3->Rebin(2);
  h4->Rebin(2);

  h1->Scale(1./h1->Integral());
  h2->Scale(1./h2->Integral());
  h3->Scale(1./h3->Integral());
  h4->Scale(1./h4->Integral());

  TLegend *legend = new TLegend(.5,.7,.85,.85);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->SetTextFont(42);
  legend->SetTextSizePixels(24);
  legend->AddEntry(h1,"semi-#mu, Narrow", "lp");
  legend->AddEntry(h2,"semi-#mu, Large", "lp");

  TLegend *legendB = new TLegend(.5,.7,.85,.85);
  legendB->SetBorderSize(0);
  legendB->SetFillColor(0);
  legendB->SetFillStyle(0);
  legendB->SetTextFont(42);
  legendB->SetTextSizePixels(24);
  legendB->AddEntry(h1,"semi-e, Narrow", "lp");
  legendB->AddEntry(h2,"semi-e, Large", "lp");

  gStyle->SetOptStat(0);
  TCanvas *c = new TCanvas("c","c", 1200 ,600);
  c->Divide(2,1);

  //h2->SetXTitle("4^{th} jet p_{T} [GeV/c]");
  //h4->SetXTitle("4^{th} jet p_{T} [GeV/c]");

  c->cd(1);
  h2->Draw("P");
  h2->GetXaxis()->SetTitleOffset(1.2);
  h1->Draw("P same");
  legend->Draw();
  c->cd(2);
  h4->Draw("P");
  h4->GetXaxis()->SetTitleOffset(1.2);
  h3->Draw("P same");
  legendB->Draw();

  //c->SaveAs("HLT_compareNW_lepton.pdf");
  //c->SaveAs("HLT_compareNW_firstJet.pdf");
  //c->SaveAs("HLT_compareNW_secondJet.pdf");
  //c->SaveAs("HLT_compareNW_thirdJet.pdf");
  c->SaveAs("HLT_compareNW_fourthJet.pdf");

}

//selected_events_trigger	
//selected_events_trigger_firstjets	
//selected_events_trigger_sndjets	
//selected_events_trigger_thirdjets	
//selected_events_trigger_fourthjets
