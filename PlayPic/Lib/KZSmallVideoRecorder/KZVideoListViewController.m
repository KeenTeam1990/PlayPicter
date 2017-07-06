//
//  KZVideoListViewController.m
//  KZWeChatSmallVideo_OC
//
//  Created by HouKangzhu on 16/7/21.
//  Copyright © 2016年 侯康柱. All rights reserved.
//

#import "KZVideoListViewController.h"
#import "KZVideoSupport.h"
#import "KZVideoConfig.h"
@interface KZVideoListViewController ()

@property (nonatomic, weak)  UICollectionView *collectionView;

@property (nonatomic, strong)  NSMutableArray *dataArr;

@property (nonatomic, assign) KZVideoViewShowType showType;

@end

static KZVideoListViewController *__currentListVC = nil;

@implementation KZVideoListViewController

- (void)showAnimationWithType:(KZVideoViewShowType)showType {
     [self closeAnimation];
}

- (void)closeAnimation {
    
    __weak typeof (self) blockSelf = self;
    [UIView animateWithDuration:0.0 delay:0.0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        _actionView.transform = CGAffineTransformTranslate(CGAffineTransformIdentity, 0, _actionView.bounds.size.width);
        _actionView.alpha = .0;
    } completion:^(BOOL finished) {
        if (self.didCloseBlock) {
            self.didCloseBlock();
        }
        [blockSelf closeView];
    }];
}

- (void)closeView {
    [_collectionView removeFromSuperview];
    _collectionView = nil;
    [_actionView removeFromSuperview];
    _actionView = nil;
    [_dataArr removeAllObjects];
    _dataArr = nil;
    __currentListVC = nil;
}
- (void)dealloc {

}

@end
