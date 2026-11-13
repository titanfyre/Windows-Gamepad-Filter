@{
RootModule = 'WindowsGamepadFilter.psm1'
ModuleVersion = '1.0.0'
GUID = 'ef9c3b61-2db6-56ad-a6f9-da9b962d1840'
Author = 'TitanCSA'
Description = 'Windows x64 Windows-Gamepad-Filter input SDK for PowerShell 7.4+. Driver installed separately.'
PowerShellVersion = '7.4'
CompatiblePSEditions = @('Core')
FunctionsToExport = @('Connect-WindowsGamepadFilterSDK','Initialize-WindowsGamepadFilterSDK','Get-WindowsGamepadFilterSDKInfo','Get-WindowsGamepadFilterSDKDevice','Receive-WindowsGamepadFilterSDKInput','Send-WindowsGamepadFilterSDKBatch','Remove-WindowsGamepadFilterSDKBatch','Stop-WindowsGamepadFilterSDKWait','Get-WindowsGamepadFilterSDKDescriptor','Send-WindowsGamepadFilterSDKInput','Disconnect-WindowsGamepadFilterSDK')
CmdletsToExport = @()
VariablesToExport = @()
AliasesToExport = @()
PrivateData = @{ PSData = @{ Tags = @('Windows','SDK','Keyboard','Mouse','Gamepad'); LicenseUri = 'https://github.com/titanfyre/Windows-Gamepad-Filter/blob/main/LICENSE'; ProjectUri = 'https://github.com/titanfyre/Windows-Gamepad-Filter'; ReleaseNotes = 'First PowerShell SDK; docs and native bridge included.' } }
}
