//
//  QCloudVPlayer.h
//  QCloudVideoPlayer
//
//  Created by jialifei on 2017/5/24.
//  Copyright © 2017年 jialifei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QCloudVideoPlayerInfo.h"





//typedef void(^QCloudVideoInfoReadyBlock)(* progess, QZVideoMonitorInfo* info, NSError* error);

typedef void (^QCloudVideoPlayBlock)(NSError* error);
typedef void (^QCloudVideoPlayStateBlock)(BOOL  isPlaying );

@protocol QCVideoPlayerViewDelegate;

@interface QCloudVPlayer : NSObject

//@property (nonatomic,strong) NSString * videoUrl;
@property (nonatomic, weak) id<QCVideoPlayerViewDelegate> delegate;

 @property (nonatomic,strong) NSArray * videoUrlsArray;

@property (nonatomic,strong) NSString * httpHeader;

@property (nonatomic,assign) CGFloat duration;

@property (nonatomic,assign) BOOL isHLS;

 @property (nonatomic,assign) QCloudVideoPlayBlock errorBlock;

@property (nonatomic,assign) QCloudVideoPlayStateBlock isPlayBlock;
 +(void)log;

-(void)reset;

-(void)run;

//-(void)startVideo;

-(id)initVideoPalyerWithFrame:(CGRect)frame andView:(UIView *)view Urls:(NSArray *)array error:(QCloudVideoPlayBlock)block; 

//-(NSString *)getLocalHttpUrlFromUR:(NSString *)url segDuration:(CGFloat)duration;

- (void) prepareDurations;
 /*封装的功能代码*/

#pragma mark - 播放控制 -
- (BOOL)play;
- (void)stop;
- (void)pause;
- (void)pause:(BOOL)stopDownload;
- (void)pauseByUser:(BOOL)byUser;//这里代码是写死的no

- (void)seek:(CGFloat)rate;
- (BOOL)canContinueSeek;
- (void)setRepeat:(BOOL)repeat;

/// 是否播放中
- (BOOL)isPlaying;

- (BOOL)isRunning; //是否正在运行

- (void)setVolume:(CGFloat)num;

#pragma mark - 设置/获取player的frame
- (void)setPlayerFrame:(CGRect)frame;

- (CGRect)getPlayerFrame;

- (void)setSyncRelease:(BOOL)enable;


/// 当前播放时间
- (CGFloat)currentTime;

- (UIImage *)currentImage;


//设置视频填充模式
- (void)setVideoFillMode:(NSString *)fillMode;
- (NSString *)getVideoFillMode;

//视频时长
- (CGFloat)duration;

@end

@protocol QCVideoPlayerViewDelegate <NSObject>

@optional

 //播放状态
- (void)playerView:(QCloudVPlayer *)playerView playIsSuccess:(BOOL)success error:(NSError *)error;

//加载前的通知
- (void)playerView:(QCloudVPlayer *)playerView willLoadWithURL:(NSString *)url isLocalFile:(BOOL)isLocal;

//加载状态
- (void)playerView:(QCloudVPlayer *)playerView loadSuccess:(BOOL)success error:(NSError *)error;

//缓冲中状态
- (void)playerViewIsWaitingData:(QCloudVPlayer *)playerView currentTime:(NSTimeInterval)time;

//加载进度
- (void)playerView:(QCloudVPlayer *)playerView loadProgress:(CGFloat)loadProgress;

//播放进度
- (void)playerView:(QCloudVPlayer *)playerView currentTime:(CGFloat)time;

//一次播放完成
- (void)playerViewOneLoopToEnd:(QCloudVPlayer *)playerView playInfo:(QCloudVideoPlayerInfo *)info;

//播放将要暂停，外部调用暂停时才会回调
- (void)playerViewWillPausePlay:(QCloudVPlayer *)playerView playInfo:(QCloudVideoPlayerInfo *)info;

//播放暂停
- (void)playerViewPausePlay:(QCloudVPlayer *)playerView playInfo:(QCloudVideoPlayerInfo *)info;

//播放将要停止，外部调用停止时才会回调
- (void)playerViewWillStopPlay:(QCloudVPlayer *)playerView playInfo:(QCloudVideoPlayerInfo *)info;

//播放停止,注意在外部调用stop不会触发回调
- (void)playerViewStopPlay:(QCloudVPlayer *)playerView playInfo:(QCloudVideoPlayerInfo *)info;

//分辨率
- (void)playerView:(QCloudVPlayer *)playerView resolution:(CGSize)size;

//加载完成
- (void)playerViewLoadComplete:(QCloudVPlayer *)playerView;
@end

