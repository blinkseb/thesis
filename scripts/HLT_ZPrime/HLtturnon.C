{
#include "tdrstyle.C"
  setTDRStyle();

  TFile f1("HLTturnon_mu_A.root");
  TFile f2("HLTturnon_mu_B.root");
  TFile f3("HLTturnon_mu_C.root");
  TFile f4("HLTturnon_mu_D.root");
  
  //TFile f1("HLTturnon_el_A.root");
  //TFile f2("HLTturnon_el_B.root");
  //TFile f3("HLTturnon_el_C.root");
  //TFile f4("HLTturnon_el_D.root");
  
  //selected_events_trigger	
  //selected_events_trigger_firstjets	
  //selected_events_trigger_sndjets	
  //selected_events_trigger_thirdjets	
  //selected_events_trigger_fourthjets

  //TString histoname="selected_events_trigger";
  //TString histoname="selected_events_trigger_firstjets";
  //TString histoname="selected_events_trigger_sndjets";
  //TString histoname="selected_events_trigger_thirdjets";
  TString histoname="selected_events_trigger_fourthjets";

  TH1F *h1 = (TH1F*) f1.Get(histoname);
  TH1F *h2 = (TH1F*) f2.Get(histoname);
  TH1F *h3 = (TH1F*) f3.Get(histoname);
  TH1F *h4 = (TH1F*) f4.Get(histoname);

  TCanvas *c = new TCanvas("c","c", 600 ,600);

  h1->SetMinimum(0.8);
  h1->SetMaximum(1.1);

  h1->GetXaxis()->SetTitleOffset(1.5);
  h1->GetYaxis()->SetTitleOffset(2.);

  h1->SetLineColor(TColor::GetColor("#ECD078"));
  h2->SetLineColor(TColor::GetColor("#D95B43"));
  h3->SetLineColor(TColor::GetColor("#542437"));
  h4->SetLineColor(TColor::GetColor("#53777A"));

  h1->SetMarkerColor(h1->GetLineColor());
  h2->SetMarkerColor(h2->GetLineColor());
  h3->SetMarkerColor(h3->GetLineColor());
  h4->SetMarkerColor(h4->GetLineColor());

  h1->SetMarkerStyle(20);
  h2->SetMarkerStyle(21);
  h3->SetMarkerStyle(22);
  h4->SetMarkerStyle(23);

  TLegend *legend = new TLegend(.2,.73,.65,.93);
  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->SetTextFont(42);
  legend->SetTextSize(0.03);
  legend->AddEntry(h1, "HLT\_MuA","lp");
  legend->AddEntry(h2, "HLT\_MuB","lp");
  legend->AddEntry(h3, "HLT\_MuC","lp");
  legend->AddEntry(h4, "HLT\_MuD","lp");

  //legend->AddEntry(h1, "HLT\_EleA","lp");
  //legend->AddEntry(h2, "HLT\_EleB","lp");
  //legend->AddEntry(h3, "HLT\_EleC","lp");
  //legend->AddEntry(h4, "HLT\_EleD","lp");

  h1->Draw("pe");
  h2->Draw("pesame");
  h3->Draw("pesame");
  h4->Draw("pesame");
  legend->Draw();

  //c->SaveAs("HLTturnon_mu_lepton_zoom.pdf");
  //c->SaveAs("HLTturnon_mu_firstJet_zoom.pdf");
  //c->SaveAs("HLTturnon_mu_secondJet_zoom.pdf");
  //c->SaveAs("HLTturnon_mu_thirdJet_zoom.pdf");
  c->SaveAs("HLTturnon_mu_fourthJet_zoom.pdf");
  
  //c->SaveAs("HLTturnon_el_lepton_zoom.pdf");
  //c->SaveAs("HLTturnon_el_firstJet_zoom.pdf");
  //c->SaveAs("HLTturnon_el_secondJet_zoom.pdf");
  //c->SaveAs("HLTturnon_el_thirdJet_zoom.pdf");
  //c->SaveAs("HLTturnon_el_fourthJet_zoom.pdf");

}

