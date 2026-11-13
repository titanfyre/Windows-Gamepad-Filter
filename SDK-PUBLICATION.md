# SDK publication status

Current source layout and registry coverage. A GitHub download is distinct from publication on a central registry.

| Target | Status | Package / documentation |
| --- | --- | --- |
| CPP/vcpkg | published_custom_registry | windows-gamepad-filter |
| CPP/conan | public_recipe_builds_locally |  [Source](packaging/native/) |
| CPP/nuget | paused_pending_owner_email_confirmation | Windows-Gamepad-Filter.Native |
| NET/nuget | built_verified_publication_on_hold_by_owner | WindowsGamepadFilter.SDK [Source](Windows-Gamepad-Filter-NET-nuget/) |
| Python/pypi | built_fixture_and_production_verified | windows-gamepad-filter [Source](Windows-Gamepad-Filter-Python-pypi/) |
| Python/conda-forge | built_tested_requires_official_review | windows-gamepad-filter [Source](packaging/conda/) |
| Rust/cargo | published_install_verified | [windows-gamepad-filter](https://crates.io/crates/windows-gamepad-filter) [Source](Windows-Gamepad-Filter-Rust-cargo/) |
| JavaScript/npm | awaiting_browser_publication_authentication | [windows-gamepad-filter](https://www.npmjs.com/package/windows-gamepad-filter) [Source](Windows-Gamepad-Filter-JavaScript-npm/) |
| Java/maven | published_install_verified | [windows-gamepad-filter](https://central.sonatype.com/artifact/io.github.titancsa/windows-gamepad-filter/1.0.0) [Source](Windows-Gamepad-Filter-Java-maven/) |
| Java/jitpack | published_install_verified | [windows-gamepad-filter](https://jitpack.io/#titanfyre/Windows-Gamepad-Filter/java-sdk-v1.0.0) [Source](Windows-Gamepad-Filter-Java-maven/) |
| Go/modules | published_install_verified | [windows-gamepad-filter](https://pkg.go.dev/github.com/titanfyre/Windows-Gamepad-Filter/Windows-Gamepad-Filter-Go-modules@v1.0.0) [Source](Windows-Gamepad-Filter-Go-modules/) |
| Go/pkg-go-dev | indexed_verified | [Documentation](https://pkg.go.dev/github.com/titanfyre/Windows-Gamepad-Filter/Windows-Gamepad-Filter-Go-modules@v1.0.0) |
| PowerShell/gallery | published_install_verified | [WindowsGamepadFilter](https://www.powershellgallery.com/packages/WindowsGamepadFilter/1.0.0) [Source](Windows-Gamepad-Filter-PowerShell-gallery/) |
| Dart/pub-dev | published_install_verified | [windows_gamepad_filter](https://pub.dev/packages/windows_gamepad_filter) [Source](Windows-Gamepad-Filter-Dart-pub-dev/) |
| Ruby/rubygems | published_install_verified | [windows-gamepad-filter](https://rubygems.org/gems/windows-gamepad-filter) [Source](Windows-Gamepad-Filter-Ruby-rubygems/) |
| PHP/packagist | composer_source_and_tag_published | [titancsa/windows-gamepad-filter](https://packagist.org/packages/titancsa/windows-gamepad-filter) |

Native SDK source and CMake/Conan/vcpkg/NuGet recipes share [`packaging/native`](packaging/native/LAYOUT.md). Previous release archives and tags remain unchanged.

Application and driver prerequisites and original licensing remain those documented by each SDK. No driver installer is bundled with these source packages.
