{
#include "tdrstyle.C"
  
  setTDRStyle();

  TCanvas* c = new TCanvas("c", "c", 800, 800);

  double x[] = {500, 750, 1000, 1250, 1500, 2000};
  double x_err[6] = {0};

  double y_narrow[] = {11.06, 9.48, 8.56, 9.81, 9.46, 9.05};
  double y_err_large[] = {0.221, 0.151, 0.449, 0.375, 0.238, 0.348};

  double y_large[] = {10.25, 9.68, 9.24, 9.90, 10.13, 10.10};
  double y_err_large[] = {0.470, 0.642, 0.293, 0.388, 0.444, 0.2001};

  double x_rs[] = {700, 1000, 1200, 1500, 2000};
  double y_rs[] = {10.09, 9.71, 9.30, 9.90, 9.45};
  double y_err_rs[] = {1.15, 0.547, 0.475, 0.579, 0.562};

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
  mg->GetYaxis()->SetTitleOffset(1.3);
  mg->GetYaxis()->SetTitle("Resolution (%)");
  TLegend l(0.65, 0.75, 0.9, 0.9);
  l.SetBorderSize(0);
  l.SetFillColor(0);
  l.SetTextFont(42);
  l.SetTextSize(0.033);
  l.AddEntry(narrow, "Narrow Z'", "LP");
  l.AddEntry(large, "Large Z'", "LP");
  l.AddEntry(rs, "K. K. gluon", "LP");
  l.Draw("same");

  c->SaveAs("signal_reso_vs_mtt.pdf");
}
