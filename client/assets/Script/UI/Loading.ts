// Learn TypeScript:
//  - https://docs.cocos.com/creator/manual/en/scripting/typescript.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

const {ccclass, property} = cc._decorator;

@ccclass
export default class Loading extends cc.Component {


    @property(cc.Button)
    entgame: cc.Button = null;
    // LIFE-CYCLE CALLBACKS:


     onLoad () {


     }

    start () {

    }

    clickEnter(){
		  console.log('clickEnter >>>>>>>>>>');
		  // 登录成功，切换到主界面
		  cc.director.loadScene('mainScene');
    }

    // update (dt) {}
}
