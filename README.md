# FS-AI_IMechE_ADS-DV_HiL

The FS-AI_IMechE_ADS-DV_HiL runs on the **Windows** version of IPG CarMaker Extended 14.1.1 **ONLY**.

https://www.ipg-automotive.com/support/customer-area/installation-files


## Installation Notes:

  1) After cloning you have the option to run 'fetch_assets.ps1' to download the 2.6GB of assets making up the 'Dynamic Driving Area' environment. It's not essential, though, and the HiL will run fine without those files.

Full installation tutorial coming soon...


## Known Issues:

  1) Cones don't appear in the Road files copied across from LTS v3.
  2) Steering resolution is limited to 1deg (not 0.1deg).
  3) ADS-DV State Machine transitions to Emergency Brake if the hydraulic brakes are commanded (the real ADS-DV does not do this).


## Development Roadmap:

  1) Fix the Known Issues...
  2) Consolidate the CAN interface to remove redundant signals and messages.


## Documentation & Tutorials:

Coming soon... Check back regularly.
