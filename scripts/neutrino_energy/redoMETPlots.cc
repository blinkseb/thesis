#include "tdrstyle.C"

void redoMETPlots() {

  setTDRStyle();

  TH1* gen_met = (TH1*) _file0->Get("gen_met");
  TH1* met = (TH1*) _file0->Get("met");
  TH1* neutrino = (TH1*) _file0->Get("neutrino");

  TCanvas* c = new TCanvas("c", "c", 800, 800);

  gen_met->SetLineColor(TColor::GetColor("#556270"));
  gen_met->SetLineWidth(2);

  neutrino->SetLineColor(TColor::GetColor("#8A9B0F"));
  neutrino->SetLineWidth(2);
  //neutrino->SetFillColor(neutrino->GetLineColor());
  //neutrino->SetFillStyle(1001);

  int col = TColor::GetColor("#C44D58");
  TColor* co = gROOT->GetColor(col);
  //co->SetAlpha(0.80);

  met->SetLineColor(col);
  met->SetLineWidth(2);
  met->SetMarkerColor(col);
  //met->SetMarkerStyle(20);
  //met->SetFillColor(met->GetLineColor());
  //met->SetFillStyle(1001);
  //
  met->GetXaxis()->SetTitle("Energy");

  met->Draw();

  gen_met->Draw("same");
  met->Draw("same");
  neutrino->Draw("same");

  TLegend* l = new TLegend(0.50 + .05, 0.65 + .08, 0.92, 0.84 + .08);
  l->SetTextFont(42);
  l->SetBorderSize(0);
  l->SetTextAlign(12);
  l->SetTextSize(0.030);
  l->SetFillColor(kWhite);
  l->AddEntry(gen_met, "Neutrino MC", "L");
  l->AddEntry(met, "MET", "L");
  l->AddEntry(neutrino, "Neutrino with p_{z}", "L");

  l->Draw();

  c->Print("plot_met_energy.pdf");
}
