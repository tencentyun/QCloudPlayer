## 开发准备

### SDK 获取

对象存储服务的 iOS SDK 的下载地址：[iOS SDK](https://github.com/tencentyun/QCloudPlayer.git) 

更多示例可参考Demo：[https://github.com/tencentyun/QCloudPlayer.git) 

### 开发准备

-  iOS 8.0+；
-  手机必须要有网络（GPRS、3G或Wifi网络等）；
### SDK 配置

#### SDK 导入

QCloudVideoPlayer的 iOS SDK压缩包组成：

 QCloudVideoPlayer.framework

压缩包中都包含了一个 framework;

将解压后的 QCloudVideoPlayer.framework 拖入工程目录，Xcode 会自动将其加入链接库列表中。


#### 工程配置
一， 工程 build Phases 中添加 

      1,libc.tbd

      2,libc++.tbd

      3,libz.tbd

      4,libresolv.9.tbd

      5,libicucore.tbd

二，工程 General  Embedded Binaries 中添加 QCloudVideoPlayer.framework

## 初始化

引入上传 SDK 的头文件 *#import "QCloudVideoPlayer.framework/Headers/QCloudVPlayer.h"*，使用播放器播放时，需要先实例化 QCloudVPlayer  对象。

#### 方法原型

```objective-c
-(id)initVideoPalyerWithFrame:(CGRect)frame andView:(UIView *)view Urls:(NSArray *)array error:(QCloudVideoPlayBlock)block ;
```

#### 参数说明

| 参数名称          | 类型           | 是否必填 | 说明                                       |
| ------------- | ------------ | ---- | ---------------------------------------- |
| frame         | CGRect    | 是    | 播放器的frame。       |
| view         | UIView *    | 是    | 承载播放器的view。      |
| array         | NSArray *    | 是    | url数组。      |
| block         | block    | 是    | error返回。      |



#### 示例

```objective-c
    player =   [[QCloudVPlayer alloc] initVideoPalyerWithFrame:CGRectMake(10, 30, s , s) andView:self.view Urls:urls error:^(NSError *error) {
        NSLog(@"now is error is ");
    }];
```


## 播放器使用

```objective-c
    player = [[QCloudVPlayer alloc] initVideoPalyerWithFrame:CGRectMake(10, 30, s , s) andView:self.view Urls:urls error:^(NSError *error) {
        NSLog(@"now is error is ");
    }];
    [player setHttpHeader:@"header"];//自定header
    player.delegate = self;
    player.isPlayBlock = ^(BOOL isPlaying) {
        NSLog(@"now is playing !");
    };
    player.isHLS = NO;
    [player run];
```

### 
### QCVideoPlayerViewDelegate

可以通过实现QCVideoPlayerViewDelegate 的方法来关注播放器的状态，加载进度，播放进度，详情可以查看QCloudVPlayer.h ；

#### 示例

```objective-c
 - (void)playerView:(QCloudVPlayer *)playerView currentTime:(CGFloat)time {
     currDurtion.text = [NSString stringWithFormat:@"%f",time];//显示播放进度
 }
```

##