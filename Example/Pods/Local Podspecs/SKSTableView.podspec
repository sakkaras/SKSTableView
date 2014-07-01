#
# Be sure to run `pod lib lint NAME.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "SKSTableView"
  s.version          = "0.1.0"
  s.summary          = "An expandable table view"
  s.description      = <<-DESC
                       KSTableView is a custom table view class extended from UITableView class. This class provides a single-level hierarchical structure(an expandable table view) for your contents. In order to minimalize the effectiveness of the table view, the default insertion and remove mechanism of UITableView (insertRowsAtIndexPaths:withRowAnimation: and deleteRowsAtIndexPaths:withRowAnimation:) is used. Main rows of your table view, which can be expandable or not must be instances of SKSTableViewCell class. Subrows can be instances of any class that is extended from UITableViewCellor or UITableViewCell itself.
                       DESC
  s.homepage         = "https://github.com/ronail/SKSTableView"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "sakkaras" => "" }
  s.source           = { :git => "https://github.com/ronail/SKSTableView.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes'
  s.resources = 'Pod/Assets/*.png'

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
