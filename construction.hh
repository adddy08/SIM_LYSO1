#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "detector.hh"

#include "MySensitiveDetector.hh"

//Detector construction class
class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
   MyDetectorConstruction();  //constructor
  ~MyDetectorConstruction();   //destructor
  
 virtual G4VPhysicalVolume *Construct() override;  //mandatory method to construct geometry
 
 
 virtual void ConstructSDandField() override;  //message to construct sensitive detectors and fields
 
 private:
 G4LogicalVolume* detLV;
  };

#endif

