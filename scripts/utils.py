import os
from pathlib import Path
import sys
import time
from urllib.error import URLError
import zipfile
from colorama import Fore, Style, init
import urllib

init(autoreset=True)

def prompt_with_default(prompt, default):
    value = input(f"{prompt} [{default}]: ").strip()
    return value if value else default

def load_animation(message, duration=2):
    print(message, end="")
    for _ in range(duration * 4):
        for ch in "|/-\\":
            sys.stdout.write(f"\r{message} {ch}")
            sys.stdout.flush()
            time.sleep(0.1)
    print("\r" + message + " ✅")
    

def section(title):
    print("\n" +Fore.CYAN + "=" * len(title))
    print(Fore.CYAN + f"🏗️  {title}")
    print(Fore.CYAN + "=" * len(title) + "\n")

def success(msg):
    print(Fore.GREEN + f"✅ {msg}")

def warning(msg):
    print(Fore.YELLOW + f"⚠️  {msg}")
    
def confirmation(message):
    confirm = input(f"{message} (y/n): ")
    if confirm.lower() == "y":
        return True
    else:
        return False
    
def download_zip(url, dest_dir=".", extract=True, chunk_size=8192):
    try:
        Path(dest_dir).mkdir(parents=True, exist_ok=True)
        filename = url.split('/')[-1]
        if not filename.endswith('.zip'):
            filename = 'download.zip'
        
        filepath = Path(dest_dir) / filename
        
        print(f"Downloading {filename}...")
        
        # Download with progress tracking
        def download_progress(block_num, block_size, total_size):
            downloaded = block_num * block_size
            percent = min(100, (downloaded / total_size) * 100)
            print(f"  Progress: {percent:.1f}%", end='\r')
        
        urllib.request.urlretrieve(url, filepath, reporthook=download_progress)
        print(f"\n✓ Downloaded to {filepath}")
        
        # Extract if requested
        if extract:
            extract_dir = Path(dest_dir) / filename.replace('.zip', '')
            print(f"Extracting to {extract_dir}...")
            
            with zipfile.ZipFile(filepath, 'r') as zip_ref:
                zip_ref.extractall(extract_dir)
            
            print(f"✓ Extracted successfully")
            return extract_dir
        
        return filepath
    
    except URLError as e:
        print(f"✗ Download failed: {e}")
        raise
    except zipfile.BadZipFile:
        print(f"✗ Downloaded file is not a valid ZIP file")
        raise


def cleanup_zip(filepath):
    try:
        os.remove(filepath)
        print(f"✓ Cleaned up {filepath}")
    except OSError as e:
        print(f"✗ Failed to remove {filepath}: {e}")
    
