Pod::Spec.new do |s|

  s.license      = "MIT"
  s.author       = { "qqc" => "20599378@qq.com" }
  s.platform     = :ios, "8.0"
  s.requires_arc  = true

  s.name         = "QqcPullToRefresh"
  s.version      = "1.0.8"
  s.summary      = "QqcPullToRefresh"
  s.homepage     = "https://github.com/xukiki/QqcPullToRefresh"
  s.source       = { :git => "https://github.com/xukiki/QqcPullToRefresh.git", :tag => "#{s.version}" }
  
  s.source_files  = ["QqcPullToRefresh/*.{h,m}"]
  
end
