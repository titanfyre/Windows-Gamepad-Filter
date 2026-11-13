require 'windows_gamepad_filter'
WindowsGamepadFilter::Interceptor.open { |client| p client.info }
