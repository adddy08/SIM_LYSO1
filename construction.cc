#include "construction.hh"
#include "detector.hh"

MyDetectorConstruction::MyDetectorConstruction()

   : detLV(nullptr) // Initialize detLV as nullptr
{}



MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
   // Define materials
   G4NistManager *nist = G4NistManager::Instance();
   G4Material *air = nist->FindOrBuildMaterial("G4_AIR");
   G4Material *lyso = nist->FindOrBuildMaterial("G4_LYSO");  // Ensure this material is available

   // Define world
   G4Box *worldBox = new G4Box("World", 50 * cm, 50 * cm, 50 * cm);
   G4LogicalVolume *worldLV = new G4LogicalVolume(worldBox, air, "World");
   G4VPhysicalVolume *worldPV = new G4PVPlacement(0, G4ThreeVector(), worldLV, "World", 0, false, 0, true);

   // Define detector
   G4Box *detBox = new G4Box("Detector", 5 * cm, 5 * cm, 5 * cm);
   detLV = new G4LogicalVolume(detBox, lyso, "Detector");  // Store it as a member variable
   new G4PVPlacement(0, G4ThreeVector(0, 0, 10 * cm), detLV, "Detector", worldLV, false, 0, true);

   // Set sensitive detector
   MySensitiveDetector *sensDet = new MySensitiveDetector("DetectorSD");
   detLV->SetSensitiveDetector(sensDet);

   return worldPV;
}

void MyDetectorConstruction::ConstructSDandField()
{
   // Now you can use detLV in this method since it's a class member
   MySensitiveDetector* sensDet = new MySensitiveDetector("DetectorSD");
   detLV->SetSensitiveDetector(sensDet);
}

