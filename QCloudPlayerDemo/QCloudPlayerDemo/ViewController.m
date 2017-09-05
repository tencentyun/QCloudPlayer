//
//  ViewController.m
//  QCloudPlayerDemo
//
//  Created by jialifei on 2017/7/25.
//  Copyright © 2017年 jialifei. All rights reserved.
//


#import "ViewController.h"
#import <QCloudVideoPlayer/QCloudVPlayer.h>

@interface ViewController ()<QCVideoPlayerViewDelegate>
{
    QCloudVPlayer * player;
    
    UILabel *durtion;
    UILabel *currDurtion;
    UILabel *loadDurtion;;
}


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setUI];
    NSArray *urls = @[@"http://sohu.vod.qingcdn.com/230/138/fjmuzlVkEteF9X8B7Ah6c3.mp4&prot=1&key=2JmP9fYWNzFWJxLbxSuB_0ASsZyuEkS7&prod=flash&pt=1",
                      @"http://sohu.vod.qingcdn.com/29/19/dwLKFjSLg6xviGOXRFhsM5.mp4&prot=1&key=d3I53fMH0POZAO_SbtqBktV86VWCGskp&prod=flash&pt=1",
                      @"http://sohu.vod.qingcdn.com/46/171/ws1jKqAQBViDl1MoeUp1a2.mp4&prot=1&key=Fbja3ehgp0s5V59oK-lsQVOACrbvhsvR&prod=flash&pt=1",
                      @"http://sohu.vod.qingcdn.com/221/25/3zf6ve5gqfxaOoxJwAZHM4.mp4&prot=1&key=5I7CoktyDPPawJilGQdnDguaFBCqiWoF&prod=flash&pt=1",
                      @"http://sohu.vod.qingcdn.com/187/121/Pxo71BafNAgKs7O6L5E6q6.mp4&prot=1&key=7W1BygT5iXoHMkwGcqNWEsE6MLd60GYB&prod=flash&pt=1"
                      ];
    
    float s = self.view.frame.size.width - 20;
    player = [[QCloudVPlayer alloc] initVideoPalyerWithFrame:CGRectMake(10, 30, s , s) andView:self.view Urls:urls error:^(NSError *error) {
        NSLog(@"now is error is ");
    }];
    [player setHttpHeader:@"header"];//自定header
    player.delegate = self;
    player.isPlayBlock = ^(BOOL isPlaying) {
        NSLog(@"now is playing !");
    };
    player.isHLS = YES;
    [player run];
    
}

-(void)setUI
{
    float s = self.view.frame.size.width-20;
    UIButton *play = [UIButton buttonWithType:UIButtonTypeCustom];
    play.frame = CGRectMake(100, s+100, 50, 50);
    play.backgroundColor = [UIColor yellowColor];
    [play setTitle:@"播放" forState:UIControlStateNormal];
    [play addTarget:self action:@selector(videoPlay) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:play];
    
    UIButton *stop = [UIButton buttonWithType:UIButtonTypeCustom];
    stop.frame = CGRectMake(250, s+100, 50, 50);
    stop.backgroundColor = [UIColor yellowColor];
    [stop setTitle:@"停止" forState:UIControlStateNormal];
    //    [stop addTarget:self action:@selector(videoStop) forControlEvents:UIControlEventTouchUpInside];
    [stop addTarget:self action:@selector(videoStop) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:stop];
    
    durtion = [[UILabel alloc] initWithFrame: CGRectMake(10, s+180, 100, 50)];;
    durtion.backgroundColor = [UIColor redColor];
    [self.view addSubview:durtion];
    
    currDurtion = [[UILabel alloc] initWithFrame: CGRectMake(150, s+180, 100, 50)];;
    currDurtion.backgroundColor = [UIColor redColor];
    [self.view addSubview:currDurtion];
    
}

-(void)videoPlay
{
    [player play];
}

-(void)videoStop
{
    [player pauseByUser: YES];
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
