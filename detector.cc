#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
//Get trac and stop it immediatey
G4Track *track = aStep->GetTrack();

 // Energy deposited in the step
    G4double edep = aStep->GetTotalEnergyDeposit();


track->SetTrackStatus(fStopAndKill); //it means as soon as the photon enters our detector it is killed and track is not propagated any further 

G4StepPoint *preStepPoint = aStep->GetPreStepPoint();  //prestepoint means photon eneters the detector
G4StepPoint *postStepPoint = aStep->GetPostStepPoint(); //this(post) is used when photon leaves the detector


//Get the photon position at pre-step 
G4ThreeVector posPhoton = preStepPoint->GetPosition();

//G4cout << "Photon position" << posPhoton << G4endl;


 // Touchable for copy number and detector details[
const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

G4int copyNo = touchable->GetCopyNumber();

//G4cout << "Copy Number:" << copyNo << G4endl; // {now it will not show the position but it will show you the detector number that has fired and later when you have maping of your detector you can reconstruct the position of photon according to copy number}

G4VPhysicalVolume *physVol = touchable->GetVolume(); //{now we have the pin structure  of our detector output -> (exact position of out detector which has been hit by photons)

G4ThreeVector posDetector = physVol->GetTranslation();//]

// Log information to G4cout
    G4cout << "Energy Deposited: " << edep / CLHEP::keV << " keV" << G4endl;
    G4cout << "Photon Position: " << posPhoton << G4endl;

G4cout << "Detector position" << posDetector << G4endl; //}

return true;
}
