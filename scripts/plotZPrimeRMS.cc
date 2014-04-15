{
#include "tdrstyle.C"
  
  setTDRStyle();

  TCanvas* c = new TCanvas("c", "c", 800, 800);

  double x[] = {500, 750, 1000, 1250, 1500, 2000};
  double x_err[6] = {0};

  double y_narrow[] = {24.47, 20.34, 20.52, 23.07, 24.89, 27.70};
  double y_err_large[] = {0.221, 0.151, 0.147, 0.170, 0.121, 0.234};

  double y_large[] = {24.07, 20.55, 21.27, 23.28, 24.44, 27.24};
  double y_err_large[] = {0.214, 0.153, 0.153, 0.171, 0.188, 0.141};

  double x_rs[] = {700, 1000, 1200, 1500, 2000};
  double y_rs[] = {20.89, 21.89, 22.66, 24.77, 26.51};
  double y_err_rs[] = {0.252, 0.244, 0.253, 0.284, 0.321};

  TGraphErrors* narrow = new TGraphErrors(6, x, y_narrow, x_err, y_err_large);

  narrow->SetMarkerStyle(20);
  narrow->SetMarkerSize(1.5);
  narrow->SetMarkerColor(TColor::GetColor("#C44D58"));
  narrow->SetLineColor(narrow->GetMarkerColor());

  TGraphErrors* large = new TGraphErrors(6, x, y_large, x_err, y_err_large);

  large->SetMarkerStyle(21);
  large->SetMarkerSize(1.5);
  large->SetMarkerColor(TColor::GetColor("#556270"));
  large->SetLineColor(large->GetMarkerColor());

  TGraphErrors* rs = new TGraphErrors(5, x_rs, y_rs, x_err, y_err_rs);

  rs->SetMarkerStyle(22);
  rs->SetMarkerSize(1.5);
  rs->SetMarkerColor(TColor::GetColor("#8A9B0F"));
  rs->SetLineColor(rs->GetMarkerColor());

  TMultiGraph* mg = new TMultiGraph();
  mg->Add(narrow, "LP");
  mg->Add(large, "LP");
  mg->Add(rs, "LP");

  mg->Draw("A");

  mg->GetXaxis()->SetTitle("m_{t#bar{t}} (GeV)");
  mg->GetYaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->SetTitle("Resolution RMS (%)");

  gPad->Update();
  mg->Draw("A");

  TLegend l(0.65, 0.15, 0.9, 0.3);
  l.SetBorderSize(0);
  l.SetFillColor(0);
  l.SetTextFont(42);
  l.SetTextSize(0.033);
  l.AddEntry(narrow, "Narrow Z'", "LP");
  l.AddEntry(large, "Large Z'", "LP");
  l.AddEntry(rs, "K. K. gluon", "LP");
  l.Draw("same");

  c->SaveAs("signal_rms_vs_mtt.pdf");
}
