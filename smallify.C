#define smallify_cxx
#include <iostream>
#include <iomanip>
#include "smallify.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

void smallify::Loop(std::string outputFileName) {
//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
  fChain->SetBranchStatus("*",0);  // disable all branches
  fChain->SetBranchStatus("HLT_isFired"                  , 1);  
  fChain->SetBranchStatus("jetAK8_IDLoose"               , 1);
  fChain->SetBranchStatus("ph_mvaVal"                    , 1);
  fChain->SetBranchStatus("ph_mvaCat"                    , 1);
  fChain->SetBranchStatus("ph_passEleVeto"               , 1);
  fChain->SetBranchStatus("ph_N"                         , 1);
  fChain->SetBranchStatus("ph_pdgId"                     , 1);
  fChain->SetBranchStatus("ph_charge"                    , 1);
  fChain->SetBranchStatus("ph_e"                         , 1);
  fChain->SetBranchStatus("ph_eta"                       , 1);
  fChain->SetBranchStatus("ph_phi"                       , 1);
  fChain->SetBranchStatus("ph_mass"                      , 1);
  fChain->SetBranchStatus("ph_pt"                        , 1);
  fChain->SetBranchStatus("ph_et"                        , 1);
  fChain->SetBranchStatus("ph_rho"                       , 1);
  fChain->SetBranchStatus("ph_superCluster_eta"          , 1);
  fChain->SetBranchStatus("ph_superCluster_phi"          , 1);
  fChain->SetBranchStatus("ph_sigmaIetaIeta"             , 1);
  fChain->SetBranchStatus("ph_hOverE"                    , 1);
  fChain->SetBranchStatus("ph_isoGamma"                  , 1);
  fChain->SetBranchStatus("ph_isoCh"                     , 1);
  fChain->SetBranchStatus("ph_passEleVeto"               , 1);
  fChain->SetBranchStatus("ph_passLooseId"               , 1);
  fChain->SetBranchStatus("ph_passMediumId"              , 1);
  fChain->SetBranchStatus("ph_passTightId"               , 1);
  fChain->SetBranchStatus("ph_mvaVal"                    , 1);
  fChain->SetBranchStatus("ph_mvaCat"                    , 1);
  fChain->SetBranchStatus("rho"                          , 1);
  fChain->SetBranchStatus("jetAK8_N"                     , 1);
  fChain->SetBranchStatus("jetAK8_pt"                    , 1);
  fChain->SetBranchStatus("jetAK8_eta"                   , 1);
  fChain->SetBranchStatus("jetAK8_mass"                  , 1);
  fChain->SetBranchStatus("jetAK8_phi"                   , 1);
  fChain->SetBranchStatus("jetAK8_e"                     , 1);
  fChain->SetBranchStatus("jetAK8_jec"                   , 1);
  fChain->SetBranchStatus("jetAK8_jecUp"                 , 1);
  fChain->SetBranchStatus("jetAK8_jecDown"               , 1);
  fChain->SetBranchStatus("jetAK8_IDLoose"               , 1);
  fChain->SetBranchStatus("jetAK8_IDTight"               , 1);
  //fChain->SetBranchStatus("jetAK8_IDTightLepVeto"        , 1);
  fChain->SetBranchStatus("jetAK8_charge"                , 1);
  //fChain->SetBranchStatus("jetAK8_Hbbtag"                , 1);
  //fChain->SetBranchStatus("jetAK8_csv"                   , 1);
  fChain->SetBranchStatus("jetAK8_DDB"                           , 1);
  fChain->SetBranchStatus("jetAK8_decDDB"                        , 1);
  fChain->SetBranchStatus("jetAK8_deep_csv_b"                    , 1);
  fChain->SetBranchStatus("jetAK8_deep_csv_bb"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_WvsQCD"                    , 1);
  fChain->SetBranchStatus("jetAK8_akx_ZvsQCD"                    , 1);
  fChain->SetBranchStatus("jetAK8_akx_ZbbvsQCD"                  , 1);
  fChain->SetBranchStatus("jetAK8_akx_HbbvsQCD"                  , 1);
  fChain->SetBranchStatus("jetAK8_akx_H4qvsQCD"                  , 1);
  fChain->SetBranchStatus("jetAK8_akx_probWcq"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_probWqq"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_probZbb"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_probZcc"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_probZqq"                   , 1);
  fChain->SetBranchStatus("jetAK8_akx_probHbb"                   , 1);
  fChain->SetBranchStatus("jetAK8_akxDec_H4qvsQCD", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_HbbvsQCD", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_WvsQCD",   1);
  fChain->SetBranchStatus("jetAK8_akxDec_ZHbbvsQCD", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_ZHccvsQCD", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_ZbbvsQCD", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_ZvsQCD",   1);
  fChain->SetBranchStatus("jetAK8_akxDec_bbvsLight", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_probHbb",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probHcc",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probHqqqq", 1);
  fChain->SetBranchStatus("jetAK8_akxDec_probWcq",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probWqq",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probZbb",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probZcc",  1);
  fChain->SetBranchStatus("jetAK8_akxDec_probZqq",  1);

  fChain->SetBranchStatus("jetAK8_tau1"                  , 1);
  fChain->SetBranchStatus("jetAK8_tau2"                  , 1);
  fChain->SetBranchStatus("jetAK8_tau3"                  , 1);
  fChain->SetBranchStatus("jetAK8_softdrop_mass"         , 1);
  fChain->SetBranchStatus("jetAK8_softdrop_massCorr"     , 1);
  fChain->SetBranchStatus("jetAK8_softdrop_jec"          , 1);
  fChain->SetBranchStatus("jetAK8_softdrop_jecUp"          , 1);
  fChain->SetBranchStatus("jetAK8_softdrop_jecDown"          , 1);
  fChain->SetBranchStatus("EVENT_event"                  , 1);
  fChain->SetBranchStatus("EVENT_run"                    , 1);
  fChain->SetBranchStatus("EVENT_lumiBlock"              , 1);

  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntries();

  Long64_t nbytes = 0, nb = 0;
  TFile* skimFile = new TFile(outputFileName.c_str(), "recreate");
  TDirectory* dir = skimFile -> mkdir("ntuplizer");
  dir->cd();
  TTree* skimTree = fChain->CloneTree(0);

  for (Long64_t jentry=0; jentry<nentries;++jentry) {
    if (stopAfter==jentry) break;
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);  nbytes += nb;
    if (jentry%25000 == 0) {
      cout.flush();
      cout << fixed << setw(4) << setprecision(2) << (float(jentry)/float(nentries))*100 << "% done: Scanned " << jentry << " events." << '\r';
    }
    if (useTriggerInfo) {
      passTrig = false;
      for(map<string,bool>::iterator it = HLT_isFired->begin(); it != HLT_isFired->end(); ++it) {
        std::cout << it->first << std::endl;
        if (it->first.find("HLT_Photon200_") != string::npos)   {
          passTrig |= (1==it->second);
        }
      }
      if (!passTrig) continue;
    }
    if (Cut(ientry) < 0) continue;
    skimTree->Fill();
  }
  skimFile->Write();
  skimFile->Close();
}

Int_t smallify::Cut(Long64_t entry) {
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  passPh  = false;
  passJet = false;
  iPh = 0;
  phVec.SetPtEtaPhiE(0,0,0,0);
  jetVec.SetPtEtaPhiE(0,0,0,0);
  for(std::vector<float>::iterator it = ph_pt->begin(); it != ph_pt->end(); ++it) {
    // THIS IS MVA ID -- following Sebastian, move to cut-based id
    //if (*it > 180                && 
    //    ( (ph_mvaCat->at(iPh)==0 && ph_mvaVal->at(iPh)>0.27) ||  // barrel
    //      (ph_mvaCat->at(iPh)==1 && ph_mvaVal->at(iPh)>0.14)     // endcap
    //    )                        && 
    //    ph_passEleVeto->at(iPh)  &&
    //    std::abs(ph_eta->at(iPh)) < 2.4

    //   )  {
      
    // LOOSE CUT-BASED ID
    if (*it > 180 && (ph_passLooseId->at(iPh) && ph_passEleVeto->at(iPh) ) ) {
      passPh = true;
      phVec.SetPtEtaPhiE(ph_pt->at(iPh), ph_eta->at(iPh), ph_phi->at(iPh), ph_e->at(iPh));

      iJet = 0;
      for(std::vector<float>::iterator jt = jetAK8_pt->begin(); jt != jetAK8_pt->end(); ++jt) {
        if ( *jt > 200                             && 
            jetAK8_IDLoose->at(iJet)   //            &&
            //jetAK8_pruned_massCorr->at(iJet) > 30 
           ) {
          passJet = true;
          jetVec.SetPtEtaPhiE(jetAK8_pt->at(iJet), jetAK8_eta->at(iJet), jetAK8_phi->at(iJet), jetAK8_e->at(iJet));
          if (phVec.DeltaR(jetVec) < 1.1) {
            passJet = false;
          }
        }
        if (passJet) break;
        ++iJet;
      }

    }
    // }
    ++iPh;
  }
  if (  passPh && passJet ) return 1;
  else return -1;
}
