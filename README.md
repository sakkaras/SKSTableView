SKSTableView
============

**SKSTableView** is a custom table view class extended from _UITableView_ class. This class provides a *single-level* hierarchical structure(an expandable table view) for your contents. In order to minimalize the effectiveness of the table view, the default insertion and remove mechanism of UITableView (_insertRowsAtIndexPaths:withRowAnimation:_ and _deleteRowsAtIndexPaths:withRowAnimation:_) is used. Main rows of your table view, which can be expandable or not must be instances of **SKSTableViewCell** class. Subrows can be instances of any class that is extended from UITableViewCellor or _UITableViewCell_ itself.

In order to use the **SKSTableView**, just drag&drop the 'SKSTableViewImp' folder into your project folder.

Sample screenshot:

![](https://github.com/sakkaras/SKSTableView/blob/master/screenshot.PNG)

