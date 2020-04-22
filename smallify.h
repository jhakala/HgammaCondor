//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr 22 14:18:07 2020 by ROOT version 6.10/09
// from TTree tree/tree
// found on file: root://cmseos.fnal.gov//store/user/jhakala/SinglePhoton/HZgamma94XSinglePhoton_Apr20_2017B/200420_155716/0000/flatTuple_47.root
//////////////////////////////////////////////////////////

#ifndef smallify_h
#define smallify_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "map"

class smallify {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

  long long stopAfter = -1;
  bool useTriggerInfo = false;

  bool passPh    = false ;
  bool passJet   = false ;
  bool passTrig  = false;
  int iPh  = 0 ;
  int iJet = 0 ;
  TLorentzVector  phVec  ;
  TLorentzVector  jetVec ;
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           ph_N;
   vector<int>     *ph_pdgId;
   vector<float>   *ph_charge;
   vector<float>   *ph_e;
   vector<float>   *ph_eta;
   vector<float>   *ph_phi;
   vector<float>   *ph_mass;
   vector<float>   *ph_pt;
   vector<float>   *ph_et;
   vector<float>   *ph_rho;
   vector<float>   *ph_superCluster_eta;
   vector<float>   *ph_superCluster_phi;
   vector<float>   *ph_sigmaIetaIeta;
   vector<float>   *ph_hOverE;
   vector<float>   *ph_isoGamma;
   vector<float>   *ph_isoCh;
   vector<bool>    *ph_passEleVeto;
   vector<int>     *ph_passLooseId;
   vector<int>     *ph_passMediumId;
   vector<int>     *ph_passTightId;
   vector<float>   *ph_mvaVal;
   vector<float>   *ph_mvaCat;
   vector<float>   *ph_Corr;
   vector<float>   *ph_energyscale;
   vector<float>   *ph_resolution;
   Float_t         rho;
   Int_t           jetAK8_N;
   vector<float>   *jetAK8_pt;
   vector<float>   *jetAK8_eta;
   vector<float>   *jetAK8_mass;
   vector<float>   *jetAK8_phi;
   vector<float>   *jetAK8_e;
   vector<float>   *jetAK8_jec;
   vector<float>   *jetAK8_jecUp;
   vector<float>   *jetAK8_jecDown;
   vector<bool>    *jetAK8_IDLoose;
   vector<bool>    *jetAK8_IDTight;
   vector<float>   *jetAK8_muf;
   vector<float>   *jetAK8_phf;
   vector<float>   *jetAK8_emf;
   vector<float>   *jetAK8_nhf;
   vector<float>   *jetAK8_chf;
   vector<float>   *jetAK8_area;
   vector<int>     *jetAK8_cm;
   vector<int>     *jetAK8_nm;
   vector<float>   *jetAK8_che;
   vector<float>   *jetAK8_ne;
   vector<float>   *jetAK8_hf_hf;
   vector<float>   *jetAK8_hf_emf;
   vector<float>   *jetAK8_hof;
   vector<int>     *jetAK8_chm;
   vector<int>     *jetAK8_neHadMult;
   vector<int>     *jetAK8_phoMult;
   vector<float>   *jetAK8_nemf;
   vector<float>   *jetAK8_cemf;
   vector<int>     *jetAK8_charge;
   vector<float>   *jetAK8_DDB;
   vector<float>   *jetAK8_decDDB;
   vector<float>   *jetAK8_deep_csv_b;
   vector<float>   *jetAK8_deep_csv_bb;
   vector<float>   *jetAK8_akx_WvsQCD;
   vector<float>   *jetAK8_akx_ZvsQCD;
   vector<float>   *jetAK8_akx_ZbbvsQCD;
   vector<float>   *jetAK8_akx_HbbvsQCD;
   vector<float>   *jetAK8_akx_H4qvsQCD;
   vector<float>   *jetAK8_akx_probWcq;
   vector<float>   *jetAK8_akx_probWqq;
   vector<float>   *jetAK8_akx_probZbb;
   vector<float>   *jetAK8_akx_probZcc;
   vector<float>   *jetAK8_akx_probZqq;
   vector<float>   *jetAK8_akx_probHbb;
   vector<float>   *jetAK8_tau1;
   vector<float>   *jetAK8_tau2;
   vector<float>   *jetAK8_tau3;
   vector<float>   *jetAK8_pull1;
   vector<float>   *jetAK8_pull2;
   vector<float>   *jetAK8_chs_pruned_mass;
   vector<float>   *jetAK8_chs_softdrop_mass;
   vector<float>   *jetAK8_chs_pruned_massCorr;
   vector<float>   *jetAK8_chs_pruned_jec;
   vector<float>   *jetAK8_chs_pruned_jecUp;
   vector<float>   *jetAK8_chs_pruned_jecDown;
   vector<float>   *jetAK8_chs_tau1;
   vector<float>   *jetAK8_chs_tau2;
   vector<float>   *jetAK8_chs_tau3;
   vector<float>   *jetAK8_softdrop_mass;
   vector<float>   *jetAK8_softdrop_massCorr;
   vector<float>   *jetAK8_softdrop_jec;
   vector<float>   *jetAK8_softdrop_jecUp;
   vector<float>   *jetAK8_softdrop_jecDown;
   vector<int>     *jetAK8_subjet_puppi_softdrop_N;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_pt;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_eta;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_mass;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_phi;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_e;
   vector<vector<int> > *jetAK8_subjet_puppi_softdrop_charge;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_csv;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_deep_csv_b;
   vector<vector<float> > *jetAK8_subjet_puppi_softdrop_deep_csv_bb;
   map<string,bool> *HLT_isFired;
   Int_t           EVENT_event;
   Int_t           EVENT_run;
   Int_t           EVENT_lumiBlock;
   Int_t           PV_N;
   Bool_t          PV_filter;
   vector<float>   *PV_chi2;
   vector<float>   *PV_ndof;
   vector<float>   *PV_rho;
   vector<float>   *PV_z;

   // List of branches
   TBranch        *b_ph_N;   //!
   TBranch        *b_ph_pdgId;   //!
   TBranch        *b_ph_charge;   //!
   TBranch        *b_ph_e;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_phi;   //!
   TBranch        *b_ph_mass;   //!
   TBranch        *b_ph_pt;   //!
   TBranch        *b_ph_et;   //!
   TBranch        *b_ph_rho;   //!
   TBranch        *b_ph_superCluster_eta;   //!
   TBranch        *b_ph_superCluster_phi;   //!
   TBranch        *b_ph_sigmaIetaIeta;   //!
   TBranch        *b_ph_hOverE;   //!
   TBranch        *b_ph_isoGamma;   //!
   TBranch        *b_ph_isoCh;   //!
   TBranch        *b_ph_passEleVeto;   //!
   TBranch        *b_ph_passLooseId;   //!
   TBranch        *b_ph_passMediumId;   //!
   TBranch        *b_ph_passTightId;   //!
   TBranch        *b_ph_mvaVal;   //!
   TBranch        *b_ph_mvaCat;   //!
   TBranch        *b_ph_Corr;   //!
   TBranch        *b_ph_energyscale;   //!
   TBranch        *b_ph_resolution;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_jetAK8_N;   //!
   TBranch        *b_jetAK8_pt;   //!
   TBranch        *b_jetAK8_eta;   //!
   TBranch        *b_jetAK8_mass;   //!
   TBranch        *b_jetAK8_phi;   //!
   TBranch        *b_jetAK8_e;   //!
   TBranch        *b_jetAK8_jec;   //!
   TBranch        *b_jetAK8_jecUp;   //!
   TBranch        *b_jetAK8_jecDown;   //!
   TBranch        *b_jetAK8_IDLoose;   //!
   TBranch        *b_jetAK8_IDTight;   //!
   TBranch        *b_jetAK8_muf;   //!
   TBranch        *b_jetAK8_phf;   //!
   TBranch        *b_jetAK8_emf;   //!
   TBranch        *b_jetAK8_nhf;   //!
   TBranch        *b_jetAK8_chf;   //!
   TBranch        *b_jetAK8_area;   //!
   TBranch        *b_jetAK8_cm;   //!
   TBranch        *b_jetAK8_nm;   //!
   TBranch        *b_jetAK8_che;   //!
   TBranch        *b_jetAK8_ne;   //!
   TBranch        *b_jetAK8_hf_hf;   //!
   TBranch        *b_jetAK8_hf_emf;   //!
   TBranch        *b_jetAK8_hof;   //!
   TBranch        *b_jetAK8_chm;   //!
   TBranch        *b_jetAK8_neHadMult;   //!
   TBranch        *b_jetAK8_phoMult;   //!
   TBranch        *b_jetAK8_nemf;   //!
   TBranch        *b_jetAK8_cemf;   //!
   TBranch        *b_jetAK8_charge;   //!
   TBranch        *b_jetAK8_DDB;   //!
   TBranch        *b_jetAK8_decDDB;   //!
   TBranch        *b_jetAK8_deep_csv_b;   //!
   TBranch        *b_jetAK8_deep_csv_bb;   //!
   TBranch        *b_jetAK8_akx_WvsQCD;   //!
   TBranch        *b_jetAK8_akx_ZvsQCD;   //!
   TBranch        *b_jetAK8_akx_ZbbvsQCD;   //!
   TBranch        *b_jetAK8_akx_HbbvsQCD;   //!
   TBranch        *b_jetAK8_akx_H4qvsQCD;   //!
   TBranch        *b_jetAK8_akx_probWcq;   //!
   TBranch        *b_jetAK8_akx_probWqq;   //!
   TBranch        *b_jetAK8_akx_probZbb;   //!
   TBranch        *b_jetAK8_akx_probZcc;   //!
   TBranch        *b_jetAK8_akx_probZqq;   //!
   TBranch        *b_jetAK8_akx_probHbb;   //!
   TBranch        *b_jetAK8_tau1;   //!
   TBranch        *b_jetAK8_tau2;   //!
   TBranch        *b_jetAK8_tau3;   //!
   TBranch        *b_jetAK8_pull1;   //!
   TBranch        *b_jetAK8_pull2;   //!
   TBranch        *b_jetAK8_chs_pruned_mass;   //!
   TBranch        *b_jetAK8_chs_softdrop_mass;   //!
   TBranch        *b_jetAK8_chs_pruned_massCorr;   //!
   TBranch        *b_jetAK8_chs_pruned_jec;   //!
   TBranch        *b_jetAK8_chs_pruned_jecUp;   //!
   TBranch        *b_jetAK8_chs_pruned_jecDown;   //!
   TBranch        *b_jetAK8_chs_tau1;   //!
   TBranch        *b_jetAK8_chs_tau2;   //!
   TBranch        *b_jetAK8_chs_tau3;   //!
   TBranch        *b_jetAK8_softdrop_mass;   //!
   TBranch        *b_jetAK8_softdrop_massCorr;   //!
   TBranch        *b_jetAK8_softdrop_jec;   //!
   TBranch        *b_jetAK8_softdrop_jecUp;   //!
   TBranch        *b_jetAK8_softdrop_jecDown;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_N;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_pt;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_eta;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_mass;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_phi;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_e;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_charge;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_csv;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_deep_csv_b;   //!
   TBranch        *b_jetAK8_subjet_puppi_softdrop_deep_csv_bb;   //!
   TBranch        *b_HLT_isFired;   //!
   TBranch        *b_EVENT_event;   //!
   TBranch        *b_EVENT_run;   //!
   TBranch        *b_EVENT_lumiBlock;   //!
   TBranch        *b_PV_N;   //!
   TBranch        *b_PV_filter;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_rho;   //!
   TBranch        *b_PV_z;   //!

   smallify(TTree *tree=0);
   virtual ~smallify();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(std::string outputFileName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef smallify_cxx
smallify::smallify(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/jhakala/SinglePhoton/HZgamma94XSinglePhoton_Apr20_2017B/200420_155716/0000/flatTuple_47.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmseos.fnal.gov//store/user/jhakala/SinglePhoton/HZgamma94XSinglePhoton_Apr20_2017B/200420_155716/0000/flatTuple_47.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmseos.fnal.gov//store/user/jhakala/SinglePhoton/HZgamma94XSinglePhoton_Apr20_2017B/200420_155716/0000/flatTuple_47.root:/ntuplizer");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

smallify::~smallify()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t smallify::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t smallify::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void smallify::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ph_pdgId = 0;
   ph_charge = 0;
   ph_e = 0;
   ph_eta = 0;
   ph_phi = 0;
   ph_mass = 0;
   ph_pt = 0;
   ph_et = 0;
   ph_rho = 0;
   ph_superCluster_eta = 0;
   ph_superCluster_phi = 0;
   ph_sigmaIetaIeta = 0;
   ph_hOverE = 0;
   ph_isoGamma = 0;
   ph_isoCh = 0;
   ph_passEleVeto = 0;
   ph_passLooseId = 0;
   ph_passMediumId = 0;
   ph_passTightId = 0;
   ph_mvaVal = 0;
   ph_mvaCat = 0;
   ph_Corr = 0;
   ph_energyscale = 0;
   ph_resolution = 0;
   jetAK8_pt = 0;
   jetAK8_eta = 0;
   jetAK8_mass = 0;
   jetAK8_phi = 0;
   jetAK8_e = 0;
   jetAK8_jec = 0;
   jetAK8_jecUp = 0;
   jetAK8_jecDown = 0;
   jetAK8_IDLoose = 0;
   jetAK8_IDTight = 0;
   jetAK8_muf = 0;
   jetAK8_phf = 0;
   jetAK8_emf = 0;
   jetAK8_nhf = 0;
   jetAK8_chf = 0;
   jetAK8_area = 0;
   jetAK8_cm = 0;
   jetAK8_nm = 0;
   jetAK8_che = 0;
   jetAK8_ne = 0;
   jetAK8_hf_hf = 0;
   jetAK8_hf_emf = 0;
   jetAK8_hof = 0;
   jetAK8_chm = 0;
   jetAK8_neHadMult = 0;
   jetAK8_phoMult = 0;
   jetAK8_nemf = 0;
   jetAK8_cemf = 0;
   jetAK8_charge = 0;
   jetAK8_DDB = 0;
   jetAK8_decDDB = 0;
   jetAK8_deep_csv_b = 0;
   jetAK8_deep_csv_bb = 0;
   jetAK8_akx_WvsQCD = 0;
   jetAK8_akx_ZvsQCD = 0;
   jetAK8_akx_ZbbvsQCD = 0;
   jetAK8_akx_HbbvsQCD = 0;
   jetAK8_akx_H4qvsQCD = 0;
   jetAK8_akx_probWcq = 0;
   jetAK8_akx_probWqq = 0;
   jetAK8_akx_probZbb = 0;
   jetAK8_akx_probZcc = 0;
   jetAK8_akx_probZqq = 0;
   jetAK8_akx_probHbb = 0;
   jetAK8_tau1 = 0;
   jetAK8_tau2 = 0;
   jetAK8_tau3 = 0;
   jetAK8_pull1 = 0;
   jetAK8_pull2 = 0;
   jetAK8_chs_pruned_mass = 0;
   jetAK8_chs_softdrop_mass = 0;
   jetAK8_chs_pruned_massCorr = 0;
   jetAK8_chs_pruned_jec = 0;
   jetAK8_chs_pruned_jecUp = 0;
   jetAK8_chs_pruned_jecDown = 0;
   jetAK8_chs_tau1 = 0;
   jetAK8_chs_tau2 = 0;
   jetAK8_chs_tau3 = 0;
   jetAK8_softdrop_mass = 0;
   jetAK8_softdrop_massCorr = 0;
   jetAK8_softdrop_jec = 0;
   jetAK8_softdrop_jecUp = 0;
   jetAK8_softdrop_jecDown = 0;
   jetAK8_subjet_puppi_softdrop_N = 0;
   jetAK8_subjet_puppi_softdrop_pt = 0;
   jetAK8_subjet_puppi_softdrop_eta = 0;
   jetAK8_subjet_puppi_softdrop_mass = 0;
   jetAK8_subjet_puppi_softdrop_phi = 0;
   jetAK8_subjet_puppi_softdrop_e = 0;
   jetAK8_subjet_puppi_softdrop_charge = 0;
   jetAK8_subjet_puppi_softdrop_csv = 0;
   jetAK8_subjet_puppi_softdrop_deep_csv_b = 0;
   jetAK8_subjet_puppi_softdrop_deep_csv_bb = 0;
   HLT_isFired = 0;
   PV_chi2 = 0;
   PV_ndof = 0;
   PV_rho = 0;
   PV_z = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ph_N", &ph_N, &b_ph_N);
   fChain->SetBranchAddress("ph_pdgId", &ph_pdgId, &b_ph_pdgId);
   fChain->SetBranchAddress("ph_charge", &ph_charge, &b_ph_charge);
   fChain->SetBranchAddress("ph_e", &ph_e, &b_ph_e);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
   fChain->SetBranchAddress("ph_mass", &ph_mass, &b_ph_mass);
   fChain->SetBranchAddress("ph_pt", &ph_pt, &b_ph_pt);
   fChain->SetBranchAddress("ph_et", &ph_et, &b_ph_et);
   fChain->SetBranchAddress("ph_rho", &ph_rho, &b_ph_rho);
   fChain->SetBranchAddress("ph_superCluster_eta", &ph_superCluster_eta, &b_ph_superCluster_eta);
   fChain->SetBranchAddress("ph_superCluster_phi", &ph_superCluster_phi, &b_ph_superCluster_phi);
   fChain->SetBranchAddress("ph_sigmaIetaIeta", &ph_sigmaIetaIeta, &b_ph_sigmaIetaIeta);
   fChain->SetBranchAddress("ph_hOverE", &ph_hOverE, &b_ph_hOverE);
   fChain->SetBranchAddress("ph_isoGamma", &ph_isoGamma, &b_ph_isoGamma);
   fChain->SetBranchAddress("ph_isoCh", &ph_isoCh, &b_ph_isoCh);
   fChain->SetBranchAddress("ph_passEleVeto", &ph_passEleVeto, &b_ph_passEleVeto);
   fChain->SetBranchAddress("ph_passLooseId", &ph_passLooseId, &b_ph_passLooseId);
   fChain->SetBranchAddress("ph_passMediumId", &ph_passMediumId, &b_ph_passMediumId);
   fChain->SetBranchAddress("ph_passTightId", &ph_passTightId, &b_ph_passTightId);
   fChain->SetBranchAddress("ph_mvaVal", &ph_mvaVal, &b_ph_mvaVal);
   fChain->SetBranchAddress("ph_mvaCat", &ph_mvaCat, &b_ph_mvaCat);
   fChain->SetBranchAddress("ph_Corr", &ph_Corr, &b_ph_Corr);
   fChain->SetBranchAddress("ph_energyscale", &ph_energyscale, &b_ph_energyscale);
   fChain->SetBranchAddress("ph_resolution", &ph_resolution, &b_ph_resolution);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("jetAK8_N", &jetAK8_N, &b_jetAK8_N);
   fChain->SetBranchAddress("jetAK8_pt", &jetAK8_pt, &b_jetAK8_pt);
   fChain->SetBranchAddress("jetAK8_eta", &jetAK8_eta, &b_jetAK8_eta);
   fChain->SetBranchAddress("jetAK8_mass", &jetAK8_mass, &b_jetAK8_mass);
   fChain->SetBranchAddress("jetAK8_phi", &jetAK8_phi, &b_jetAK8_phi);
   fChain->SetBranchAddress("jetAK8_e", &jetAK8_e, &b_jetAK8_e);
   fChain->SetBranchAddress("jetAK8_jec", &jetAK8_jec, &b_jetAK8_jec);
   fChain->SetBranchAddress("jetAK8_jecUp", &jetAK8_jecUp, &b_jetAK8_jecUp);
   fChain->SetBranchAddress("jetAK8_jecDown", &jetAK8_jecDown, &b_jetAK8_jecDown);
   fChain->SetBranchAddress("jetAK8_IDLoose", &jetAK8_IDLoose, &b_jetAK8_IDLoose);
   fChain->SetBranchAddress("jetAK8_IDTight", &jetAK8_IDTight, &b_jetAK8_IDTight);
   fChain->SetBranchAddress("jetAK8_muf", &jetAK8_muf, &b_jetAK8_muf);
   fChain->SetBranchAddress("jetAK8_phf", &jetAK8_phf, &b_jetAK8_phf);
   fChain->SetBranchAddress("jetAK8_emf", &jetAK8_emf, &b_jetAK8_emf);
   fChain->SetBranchAddress("jetAK8_nhf", &jetAK8_nhf, &b_jetAK8_nhf);
   fChain->SetBranchAddress("jetAK8_chf", &jetAK8_chf, &b_jetAK8_chf);
   fChain->SetBranchAddress("jetAK8_area", &jetAK8_area, &b_jetAK8_area);
   fChain->SetBranchAddress("jetAK8_cm", &jetAK8_cm, &b_jetAK8_cm);
   fChain->SetBranchAddress("jetAK8_nm", &jetAK8_nm, &b_jetAK8_nm);
   fChain->SetBranchAddress("jetAK8_che", &jetAK8_che, &b_jetAK8_che);
   fChain->SetBranchAddress("jetAK8_ne", &jetAK8_ne, &b_jetAK8_ne);
   fChain->SetBranchAddress("jetAK8_hf_hf", &jetAK8_hf_hf, &b_jetAK8_hf_hf);
   fChain->SetBranchAddress("jetAK8_hf_emf", &jetAK8_hf_emf, &b_jetAK8_hf_emf);
   fChain->SetBranchAddress("jetAK8_hof", &jetAK8_hof, &b_jetAK8_hof);
   fChain->SetBranchAddress("jetAK8_chm", &jetAK8_chm, &b_jetAK8_chm);
   fChain->SetBranchAddress("jetAK8_neHadMult", &jetAK8_neHadMult, &b_jetAK8_neHadMult);
   fChain->SetBranchAddress("jetAK8_phoMult", &jetAK8_phoMult, &b_jetAK8_phoMult);
   fChain->SetBranchAddress("jetAK8_nemf", &jetAK8_nemf, &b_jetAK8_nemf);
   fChain->SetBranchAddress("jetAK8_cemf", &jetAK8_cemf, &b_jetAK8_cemf);
   fChain->SetBranchAddress("jetAK8_charge", &jetAK8_charge, &b_jetAK8_charge);
   fChain->SetBranchAddress("jetAK8_DDB", &jetAK8_DDB, &b_jetAK8_DDB);
   fChain->SetBranchAddress("jetAK8_decDDB", &jetAK8_decDDB, &b_jetAK8_decDDB);
   fChain->SetBranchAddress("jetAK8_deep_csv_b", &jetAK8_deep_csv_b, &b_jetAK8_deep_csv_b);
   fChain->SetBranchAddress("jetAK8_deep_csv_bb", &jetAK8_deep_csv_bb, &b_jetAK8_deep_csv_bb);
   fChain->SetBranchAddress("jetAK8_akx_WvsQCD", &jetAK8_akx_WvsQCD, &b_jetAK8_akx_WvsQCD);
   fChain->SetBranchAddress("jetAK8_akx_ZvsQCD", &jetAK8_akx_ZvsQCD, &b_jetAK8_akx_ZvsQCD);
   fChain->SetBranchAddress("jetAK8_akx_ZbbvsQCD", &jetAK8_akx_ZbbvsQCD, &b_jetAK8_akx_ZbbvsQCD);
   fChain->SetBranchAddress("jetAK8_akx_HbbvsQCD", &jetAK8_akx_HbbvsQCD, &b_jetAK8_akx_HbbvsQCD);
   fChain->SetBranchAddress("jetAK8_akx_H4qvsQCD", &jetAK8_akx_H4qvsQCD, &b_jetAK8_akx_H4qvsQCD);
   fChain->SetBranchAddress("jetAK8_akx_probWcq", &jetAK8_akx_probWcq, &b_jetAK8_akx_probWcq);
   fChain->SetBranchAddress("jetAK8_akx_probWqq", &jetAK8_akx_probWqq, &b_jetAK8_akx_probWqq);
   fChain->SetBranchAddress("jetAK8_akx_probZbb", &jetAK8_akx_probZbb, &b_jetAK8_akx_probZbb);
   fChain->SetBranchAddress("jetAK8_akx_probZcc", &jetAK8_akx_probZcc, &b_jetAK8_akx_probZcc);
   fChain->SetBranchAddress("jetAK8_akx_probZqq", &jetAK8_akx_probZqq, &b_jetAK8_akx_probZqq);
   fChain->SetBranchAddress("jetAK8_akx_probHbb", &jetAK8_akx_probHbb, &b_jetAK8_akx_probHbb);
   fChain->SetBranchAddress("jetAK8_tau1", &jetAK8_tau1, &b_jetAK8_tau1);
   fChain->SetBranchAddress("jetAK8_tau2", &jetAK8_tau2, &b_jetAK8_tau2);
   fChain->SetBranchAddress("jetAK8_tau3", &jetAK8_tau3, &b_jetAK8_tau3);
   fChain->SetBranchAddress("jetAK8_pull1", &jetAK8_pull1, &b_jetAK8_pull1);
   fChain->SetBranchAddress("jetAK8_pull2", &jetAK8_pull2, &b_jetAK8_pull2);
   fChain->SetBranchAddress("jetAK8_chs_pruned_mass", &jetAK8_chs_pruned_mass, &b_jetAK8_chs_pruned_mass);
   fChain->SetBranchAddress("jetAK8_chs_softdrop_mass", &jetAK8_chs_softdrop_mass, &b_jetAK8_chs_softdrop_mass);
   fChain->SetBranchAddress("jetAK8_chs_pruned_massCorr", &jetAK8_chs_pruned_massCorr, &b_jetAK8_chs_pruned_massCorr);
   fChain->SetBranchAddress("jetAK8_chs_pruned_jec", &jetAK8_chs_pruned_jec, &b_jetAK8_chs_pruned_jec);
   fChain->SetBranchAddress("jetAK8_chs_pruned_jecUp", &jetAK8_chs_pruned_jecUp, &b_jetAK8_chs_pruned_jecUp);
   fChain->SetBranchAddress("jetAK8_chs_pruned_jecDown", &jetAK8_chs_pruned_jecDown, &b_jetAK8_chs_pruned_jecDown);
   fChain->SetBranchAddress("jetAK8_chs_tau1", &jetAK8_chs_tau1, &b_jetAK8_chs_tau1);
   fChain->SetBranchAddress("jetAK8_chs_tau2", &jetAK8_chs_tau2, &b_jetAK8_chs_tau2);
   fChain->SetBranchAddress("jetAK8_chs_tau3", &jetAK8_chs_tau3, &b_jetAK8_chs_tau3);
   fChain->SetBranchAddress("jetAK8_softdrop_mass", &jetAK8_softdrop_mass, &b_jetAK8_softdrop_mass);
   fChain->SetBranchAddress("jetAK8_softdrop_massCorr", &jetAK8_softdrop_massCorr, &b_jetAK8_softdrop_massCorr);
   fChain->SetBranchAddress("jetAK8_softdrop_jec", &jetAK8_softdrop_jec, &b_jetAK8_softdrop_jec);
   fChain->SetBranchAddress("jetAK8_softdrop_jecUp", &jetAK8_softdrop_jecUp, &b_jetAK8_softdrop_jecUp);
   fChain->SetBranchAddress("jetAK8_softdrop_jecDown", &jetAK8_softdrop_jecDown, &b_jetAK8_softdrop_jecDown);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_N", &jetAK8_subjet_puppi_softdrop_N, &b_jetAK8_subjet_puppi_softdrop_N);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_pt", &jetAK8_subjet_puppi_softdrop_pt, &b_jetAK8_subjet_puppi_softdrop_pt);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_eta", &jetAK8_subjet_puppi_softdrop_eta, &b_jetAK8_subjet_puppi_softdrop_eta);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_mass", &jetAK8_subjet_puppi_softdrop_mass, &b_jetAK8_subjet_puppi_softdrop_mass);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_phi", &jetAK8_subjet_puppi_softdrop_phi, &b_jetAK8_subjet_puppi_softdrop_phi);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_e", &jetAK8_subjet_puppi_softdrop_e, &b_jetAK8_subjet_puppi_softdrop_e);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_charge", &jetAK8_subjet_puppi_softdrop_charge, &b_jetAK8_subjet_puppi_softdrop_charge);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_csv", &jetAK8_subjet_puppi_softdrop_csv, &b_jetAK8_subjet_puppi_softdrop_csv);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_deep_csv_b", &jetAK8_subjet_puppi_softdrop_deep_csv_b, &b_jetAK8_subjet_puppi_softdrop_deep_csv_b);
   fChain->SetBranchAddress("jetAK8_subjet_puppi_softdrop_deep_csv_bb", &jetAK8_subjet_puppi_softdrop_deep_csv_bb, &b_jetAK8_subjet_puppi_softdrop_deep_csv_bb);
   fChain->SetBranchAddress("HLT_isFired", &HLT_isFired, &b_HLT_isFired);
   fChain->SetBranchAddress("EVENT_event", &EVENT_event, &b_EVENT_event);
   fChain->SetBranchAddress("EVENT_run", &EVENT_run, &b_EVENT_run);
   fChain->SetBranchAddress("EVENT_lumiBlock", &EVENT_lumiBlock, &b_EVENT_lumiBlock);
   fChain->SetBranchAddress("PV_N", &PV_N, &b_PV_N);
   fChain->SetBranchAddress("PV_filter", &PV_filter, &b_PV_filter);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_rho", &PV_rho, &b_PV_rho);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   Notify();
}

Bool_t smallify::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void smallify::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
#endif // #ifdef smallify_cxx
