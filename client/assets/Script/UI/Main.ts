import { Global } from "../Data/Global";
import dataMgr from "../Data/DataMgr";



const {ccclass, property} = cc._decorator;

@ccclass
export default class Main extends cc.Component {
    @property(cc.Label)
    uisectName: cc.Label = null;     

    @property(cc.Label)
    uidurDate: cc.Label = null;

    @property(cc.Label)
    uijieTime: cc.Label = null; 

    @property(cc.Label)
    uijieName: cc.Label = null;     

    @property(cc.Label)
    uipopNum: cc.Label = null;     

    @property(cc.Label)
    uipopLimit: cc.Label = null;      

    @property(cc.Label)
    uipopSpeed: cc.Label = null;       

    @property(cc.Label)
    uilingshi: cc.Label = null;         

    @property(cc.Label)
    uiinDisciple: cc.Label = null;     
    
    @property(cc.Label)
    uiinDiscipleLimit: cc.Label = null;    
    
    @property(cc.Label)
    uioutDisciple: cc.Label = null;    
    
    @property(cc.Label)
    uioutDiscipleLimit: cc.Label = null;    
    
    @property(cc.Label)
    uiidleDisciple: cc.Label = null;    
    
    @property(cc.Label)
    uiidleDiscipleSpeed: cc.Label = null;        

    @property(cc.Label)
    uileaderName: cc.Label = null;     

    @property(cc.Label)
    uiexp: cc.Label = null;   
    
    @property(cc.Label)
    uifighting: cc.Label = null;   
    
    @property(cc.Label)
    uilift: cc.Label = null;   
    
    @property(cc.Label)
    uiupProb: cc.Label = null;       

    // LIFE-CYCLE CALLBACKS:

     onLoad () {
        

     }

    start () {
        this.updateTime();
        this.schedule(this.updateTime,1);

    }

    updateTime(){
        dataMgr.durTime += 1;

        this.uidurDate.string = "历经" + Global.calculateYear(dataMgr.durTime);
        this.uijieTime.string = "大劫倒计时：";
        this.uijieName.string = "百年大劫";

        this.uipopNum.string = Global.shortNum(dataMgr.popNum) + "/";
        this.uipopLimit.string = Global.shortNum(dataMgr.popLimit);
        this.uipopSpeed.string = Global.shortNum(dataMgr.popSpeed) + "/年";
        this.uilingshi.string = Global.shortNum(dataMgr.lingshi);
        this.uiinDisciple.string = Global.shortNum(dataMgr.inDisciple)+ "/";
        this.uiinDiscipleLimit.string = Global.shortNum(dataMgr.inDiscipleLimit);
        this.uioutDisciple.string = Global.shortNum(dataMgr.outDisciple)+ "/";
        this.uioutDiscipleLimit.string = Global.shortNum(dataMgr.outDiscipleLimit);
        this.uiidleDisciple.string =  Global.shortNum(dataMgr.idleDisciple) + "+";
        this.uiidleDiscipleSpeed.string = Global.shortNum(dataMgr.idleDiscipleSpeed) + "/年";

        this.uileaderName.string = dataMgr.leaderInfo.nickName;
        this.uiexp.string = "元气:" + dataMgr.leaderInfo.curExp + "/" + dataMgr.leaderInfo.expLimit;
        this.uifighting.string = "战斗力:" + dataMgr.leaderInfo.curFighting + "/" + dataMgr.leaderInfo.fightingLimit;
        this.uilift.string = "寿元:" + dataMgr.leaderInfo.curLift + "/" + dataMgr.leaderInfo.liftLimit;
        this.uiupProb.string = "突破几率:" + dataMgr.leaderInfo.upProb + "%";

        if (dataMgr.durTime%dataMgr.saveInterval == 0)
        {
            dataMgr.saveData();
        }
    }

    update (dt) {


    }
}
