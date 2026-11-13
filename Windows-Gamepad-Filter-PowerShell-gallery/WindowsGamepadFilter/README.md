# Windows-Gamepad-Filter PowerShell SDK

`Install-Module WindowsGamepadFilter -Scope CurrentUser`

Requires PowerShell 7.4+ on Windows x64. Supported families: hid, xinput, xinputhid, gip. The native product SDK and license/trial behavior are unchanged. No driver is installed on import or construction.

```powershell
Import-Module WindowsGamepadFilter
$client = Connect-WindowsGamepadFilterSDK
try { Get-WindowsGamepadFilterSDKInfo -Client $client }
finally { Disconnect-WindowsGamepadFilterSDK -Client $client }
```

See [API guide](docs/API.md) and `Get-Command -Module WindowsGamepadFilter`. The matching driver is installed separately.
