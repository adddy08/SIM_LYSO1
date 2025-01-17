#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4SystemOfUnits.hh"

// Sensitive detector class for detecting photons
class MySensitiveDetector : public G4VSensitiveDetector
{
public:
MySensitiveDetector(G4String);
~MySensitiveDetector();

private:
virtual G4bool ProcessHits(G4Step *, G4TouchableHistory* ROhist); // ProcessHits is called whenever a particle hits the sensitive detector
};

#endif

 
