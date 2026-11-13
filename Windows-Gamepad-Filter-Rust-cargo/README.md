# Windows-Gamepad-Filter Rust SDK

`cargo add windows-gamepad-filter`

Windows x64 MSVC Rust 1.82+. The product DLL/import library is bundled; build.rs places the DLL beside Cargo executables. Copy `native/WindowsGamepadFilterBridge.dll` beside a deployed executable. No driver is installed or capture started during package installation or construction.

```rust,no_run
use windows_gamepad_filter::Interceptor;
let mut client = Interceptor::new()?;
let info = client.info()?;
# Ok::<(), Box<dyn std::error::Error>>(())
```

[API](docs/API.md). Native source: product repository C-ffi directory. Original licensing/driver prerequisites remain unchanged.
