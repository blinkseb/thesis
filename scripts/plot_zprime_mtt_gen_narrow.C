{

#include "tdrstyle.C"
  
  setTDRStyle();

  TFile* a = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M500GeV_W5GeV/extracted_mc_1_1_cOJ.root");
  TFile* b = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M750GeV_W7p5GeV/extracted_mc_1_2_keS.root");
  TFile* c = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M1000GeV_W10GeV/extracted_mc_1_2_SBk.root");
  TFile* d = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M1250GeV_W12p5GeV/extracted_mc_1_2_XVu.root");
  TFile* e = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M1500GeV_W15GeV/extracted_mc_1_2_VYF.root");
  TFile* f = TFile::Open("root://lyogrid06.in2p3.fr//dpm/in2p3.fr/home/cms/data/store/user/sbrochet/HTT/Extracted/MC/Summer12/20Mar14/semimu/ZPrimeToTTJets_M2000GeV_W20GeV/extracted_mc_1_1_OTL.root");

  TTree* mtt_a = (TTree*) a->Get("Mtt");
  TTree* mtt_b = (TTree*) b->Get("Mtt");
  TTree* mtt_c = (TTree*) c->Get("Mtt");
  TTree* mtt_d = (TTree*) d->Get("Mtt");
  TTree* mtt_e = (TTree*) e->Get("Mtt");
  TTree* mtt_f = (TTree*) f->Get("Mtt");

  mtt_a->Draw("MC_mtt>>h_a(500,400,2100");
  TH1* h_a = (TH1*) gDirectory->Get("h_a");
  h_a->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_b->Draw("MC_mtt>>h_b(500,400,2100");
  TH1* h_b = (TH1*) gDirectory->Get("h_b");
  h_b->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_c->Draw("MC_mtt>>h_c(500,400,2100");
  TH1* h_c = (TH1*) gDirectory->Get("h_c");
  h_c->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_d->Draw("MC_mtt>>h_d(500,400,2100");
  TH1* h_d = (TH1*) gDirectory->Get("h_d");
  h_d->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_e->Draw("MC_mtt>>h_e(500,400,2100");
  TH1* h_e = (TH1*) gDirectory->Get("h_e");
  h_e->SetLineColor(TColor::GetColor("#C44D58"));

  mtt_f->Draw("MC_mtt>>h_f(500,400,2100");
  TH1* h_f = (TH1*) gDirectory->Get("h_f");
  h_f->SetLineColor(TColor::GetColor("#C44D58"));

  h_a->SetNdivisions(505);
  h_a->SetXTitle("m_{t#bar{t}}");

  TCanvas* c1 = new TCanvas("c", "c", 800, 600);

  h_a->Draw("c");
  h_b->Draw("c same");
  h_c->Draw("c same");
  h_d->Draw("c same");
  h_e->Draw("c same");
  h_f->Draw("c same");

  TLatex l;
  l.SetTextFont(42);
  l.SetTextSize(0.033);
  l.DrawLatexNDC(0.7, 0.85, "#Gamma / M_{Z'} = 1%");

  c1->SaveAs("mtt_zprime_narrow_gen.pdf");
}
