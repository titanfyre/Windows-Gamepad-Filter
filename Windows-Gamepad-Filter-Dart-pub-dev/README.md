# Windows-Gamepad-Filter Dart / Flutter Windows SDK

`dart pub add windows_gamepad_filter` or `flutter pub add windows_gamepad_filter`

Windows x64 and Dart 3.4+. Direct FFI to the product SDK; no Python dependency or driver installer. Supported families: hid, xinput, xinputhid, gip.

```dart
import 'package:windows_gamepad_filter/windows_gamepad_filter.dart';
Future<void> main() async {
  final client = await Interceptor.open();
  try { print(client.info()); } finally { client.close(); }
}
```

Calls are synchronous: use a worker isolate for a Flutter UI. Send `client.cancellationToken` to another isolate to cancel an active receive; the token contains only an immutable library path and session number. See [API documentation](doc/API.md).

For compiled Dart and deployed Flutter Windows apps, bundle `lib/native/WindowsGamepadFilterBridge.dll` next to the executable, or provide its absolute `libraryPath`. This plain Dart package does not automatically alter a Flutter build. Native licensing, trial limits and driver requirements are unchanged.
