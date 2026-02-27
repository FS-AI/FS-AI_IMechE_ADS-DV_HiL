param(
    [string]$Version = "assets-v1.0"
)

$ErrorActionPreference = "Stop"

$Repo = "FS-AI/FS-AI_IMechE_ADS-DV_HiL"
$AssetName = "data_FS_AI_Circuit.zip"
$AssetDir = "MovieNX\data_FS_AI_Circuit"

$DownloadUrl = "https://github.com/$Repo/releases/download/$Version/$AssetName"

Write-Host "Downloading assets from $DownloadUrl"

if (!(Test-Path $AssetDir)) {
    New-Item -ItemType Directory -Path $AssetDir | Out-Null
}

$TempZip = "$env:TEMP\$AssetName"

Invoke-WebRequest -Uri $DownloadUrl -OutFile $TempZip

Expand-Archive -Path $TempZip -DestinationPath $AssetDir -Force

Remove-Item $TempZip

Write-Host "Assets downloaded successfully."

Pause