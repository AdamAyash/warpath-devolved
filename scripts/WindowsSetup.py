import zipfile
import subprocess
from pathlib import Path
from urllib.request import urlretrieve
from Utilities import Loader
import os
import Globals

def startWindowsSetup():
     try:
      shouldDownloadPremake = input("Do you wish to download \"Premake\"? y/n ")
      if(shouldDownloadPremake == "y" or shouldDownloadPremake == "Y" or shouldDownloadPremake == "yes"):
          animationLoader = Loader("Generating project files... ", "Project setup is complete.", Globals.ANIMATION_TIMEOUT).start()
          Path(Globals.VENDOR_FOLDER_RELATIVE_PATH).mkdir(parents=True, exist_ok=True)
          urlretrieve(Globals.PREMAKE5_WINDOWS_DOWNLOAD_URL, Globals.PREMAKE5_ZIP_FILE_NAME)
      elif(shouldDownloadPremake != "n" and shouldDownloadPremake != "no"):
          print("Incorrect input.")
  
      with zipfile.ZipFile(Globals.PREMAKE5_ZIP_FILE_NAME, 'r') as zipFileReference:
          zipFileReference.extractall(Globals.VENDOR_FOLDER_RELATIVE_PATH)
  
      os.remove(Globals.PREMAKE5_ZIP_FILE_NAME)
      subprocess.call(["/vendor/bin/premake5.exe", "vs2022"])
      animationLoader.stop()
      print("WCC Engine setup has completed.")
     except:
         print("An error occurred while trying to generate the project. Please, try again.")