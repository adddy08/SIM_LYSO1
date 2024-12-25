#include "generator.hh"

#include "Randomize.hh"


MyPrimaryGenerator::MyPrimaryGenerator()
{
fParticleGun = new G4ParticleGun(1);
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable->FindParticle("gamma");
    fParticleGun->SetParticleDefinition(particle);
}


MyPrimaryGenerator::~MyPrimaryGenerator()
{
delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{


    // Random position within a cube of side 10 mm
    G4double x = (G4UniformRand() - 0.5) * 10.0 * mm;
    G4double y = (G4UniformRand() - 0.5) * 10.0 * mm;
    G4double z = 0.0;
    G4ThreeVector pos(x, y, z);

    // Momentum directed along the z-axis
    G4ThreeVector mom(0., 0., 1.);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(500. * keV);

    fParticleGun->GeneratePrimaryVertex(anEvent);
}

