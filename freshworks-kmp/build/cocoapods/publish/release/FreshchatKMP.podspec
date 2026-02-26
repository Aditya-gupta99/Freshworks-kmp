Pod::Spec.new do |spec|
    spec.name                     = 'FreshchatKMP'
    spec.version                  = '1.0.0'
    spec.homepage                 = 'https://github.com/your-org/freshchat-kmp'
    spec.source                   = { :http=> ''}
    spec.authors                  = ''
    spec.license                  = ''
    spec.summary                  = 'KMP Freshchat wrapper'
    spec.vendored_frameworks      = 'freshworks_kmp.xcframework'
    spec.libraries                = 'c++'
    spec.ios.deployment_target    = '13.0'
    spec.dependency 'FreshchatSDK'
end
