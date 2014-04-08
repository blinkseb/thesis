{

#include "tdrstyle.C"
  
  setTDRStyle();

  TFile* a = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/30Mar14/semimu/RSGluonToTT_M-700/extracted_mc_1_1_6HV.root");
  TFile* b = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/30Mar14/semimu/RSGluonToTT_M-1000/extracted_mc_1_1_f4Z.root");
  TFile* c = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/30Mar14/semimu/RSGluonToTT_M-1200/extracted_mc_1_1_0KU.root");
  TFile* d = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/30Mar14/semimu/RSGluonToTT_M-1500/extracted_mc_1_1_gNV.root");

  TTree* mtt_a = (TTree*) a->Get("Mtt");
  TTree* mtt_b = (TTree*) b->Get("Mtt");
  TTree* mtt_c = (TTree*) c->Get("Mtt");
  TTree* mtt_d = (TTree*) d->Get("Mtt");

  mtt_a->Draw("MC_mtt>>h_a(100,600,1600");
  TH1* h_a = (TH1*) gDirectory->Get("h_a");
  h_a->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_b->Draw("MC_mtt>>h_b(100,600,1600");
  TH1* h_b = (TH1*) gDirectory->Get("h_b");
  h_b->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_c->Draw("MC_mtt>>h_c(100,600,1600");
  TH1* h_c = (TH1*) gDirectory->Get("h_c");
  h_c->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_d->Draw("MC_mtt>>h_d(100,600,1600");
  TH1* h_d = (TH1*) gDirectory->Get("h_d");
  h_d->SetLineColor(TColor::GetColor("#C44D58"));

  h_a->SetNdivisions(505);
  h_a->SetXTitle("m_{t#bar{t}}");

  h_a->Draw("");
  h_b->Draw("same");
  h_c->Draw("same");
  h_d->Draw("same");

  c1->SaveAs("mtt_rsgluons_gen.pdf");
}
