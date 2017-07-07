Pod::Spec.new do |s|
  s.name         = "SKSTableView"
  s.version      = "0.0.3"
  s.summary      = "An expandable table view."

  s.description  = <<-DESC
                   SKSTableView is a custom table view class extended from UITableView class.
                   This class provides a single-level hierarchical structure(an expandable table view) for your contents.
                   In order to minimalize the effectiveness of the table view, the default insertion and remove mechanism of UITableView (insertRowsAtIndexPaths:withRowAnimation: and deleteRowsAtIndexPaths:withRowAnimation:) is used.
                   Main rows of your table view, which can be expandable or not must be instances of SKSTableViewCell class. Subrows can be instances of any class that is extended from UITableViewCellor or UITableViewCell itself.
                   DESC

  s.homepage     = "https://github.com/weekwood/SKSTableView"
  s.screenshots  = "https://raw.githubusercontent.com/weekwood/SKSTableView/master/screenshot.PNG"
  s.license      = "MIT"
  s.author       =  "sakkaras"
  s.platform     = :ios, '7.0'
  s.source       = { :git => "https://github.com/weekwood/SKSTableView.git",:tag =>'0.0.3'}
  s.source_files  = "SKSTableView/SKSTableView.{h,m}","SKSTableView/SKSTableViewCell.{h,m}","SKSTableView/SKSTableViewCellIndicator.{h,m}"
  s.resources = "SKSTableView/*.png"
  s.requires_arc = true

end
