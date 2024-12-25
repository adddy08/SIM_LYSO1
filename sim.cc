#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"


int main(int argc, char** argv)
{
   //Initialize the Run manager
   G4RunManager* runManager = new G4RunManager();
   
   //set up the detector construction, Physics List, and Action Initializations 
   runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    runManager->SetUserInitialization(new MyActionInitialization());
   
   //Initialize Run Manager
   runManager->Initialize();
   
   // Initialize the User Interface (UI) for Geant4
   G4UIExecutive* ui = new G4UIExecutive(argc, argv);
   
     // Initialize Visualization Manager
   G4VisManager* visManager = new G4VisExecutive();
   visManager->Initialize();
   
      // Get UI Manager for applying commands
   G4UImanager* UImanager =  G4UImanager:: GetUIpointer();
   
   // Set visualization options
   
   UImanager->ApplyCommand("/vis/open OGL 600x600-0+0");// Open OpenGL visualization
   UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");// Set view directio
    UImanager->ApplyCommand("/vis/drawVolume"); // Draw volumes
     UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true"); // Auto-refresh for visualization
     UImanager->ApplyCommand("/vis/scene/add/trajectories smooth"); // Add trajectories in a smooth manner
     UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");// Accumulate event data for visualization
    
      // Start the event generation (change the number of events as needed)
    UImanager->ApplyCommand("/run/beamOn 10");  // Run 10 events (change as needed)

    // Start the interactive session
   ui->SessionStart();
   
    // Clean up the memory (delete the UI and visualization manager)
    delete visManager;
    delete ui;
    delete runManager;
   
 return 0;
}	

