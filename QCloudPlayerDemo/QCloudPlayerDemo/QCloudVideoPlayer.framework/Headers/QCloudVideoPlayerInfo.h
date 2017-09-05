//
//  QCloudVideoPlayerInfo.h
//  QCloudVideoPlayer
//
//  Created by jialifei on 2017/6/15.
//  Copyright © 2017年 jialifei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AudioToolbox/AudioToolbox.h>
 @interface QCloudVideoPlayerInfo : NSObject

 @property(nonatomic, strong) UIImage* curImage;
@property(nonatomic, assign) BOOL manualStop;
@property(nonatomic, assign) BOOL playToEnd;
@property(nonatomic, assign) CGFloat currentPlayTime; //已经播放的时长，curTime在播完时会显示0，而currentPlayTime则显示已经播放的时间
@property(nonatomic, assign) CGFloat duration;
 @property(nonatomic, assign) CGFloat downloadSize; //文件下载的大小，单位M
@property(nonatomic, assign) CGFloat playedTotalTime; //不去重总时长



@end
