import FigureData from "./FigureData";
declare let encryptjs: any;
var encrypy_key = "zhenglipaoxuxiankun";

class DataMgr {
    private static inst: DataMgr = null;
    public static getInstance(): DataMgr {
        if (this.inst == null) {
            this.inst = new DataMgr();
        }
        return this.inst;
    }
    public saveInterval:number = 5; //数据刷新间隔

    public sectName: string = "青云门";
	public durTime: number = 0; 
    public jieTime: number = 0;

    public popNum: number = 0; 
    public popLimit: number = 0;
    public popSpeed: number = 0;
    public inDisciple: number = 0;
    public inDiscipleLimit: number = 0;
    public outDisciple: number = 0;
    public outDiscipleLimit: number = 0;    
    public idleDisciple: number = 0;
    public idleDiscipleSpeed: number = 0;
    public lingshi: number = 0;

    
    public leaderInfo: FigureData = new FigureData();
    public figureList: Map<number, FigureData>;

    public constructor(){   //  构造
        this.loadData();
    }

    public initData(){
        this.leaderInfo.nickName = "";
    }

	public loadData(){ 
        let tempdurTime = JSON.parse(cc.sys.localStorage.getItem("durTime"));
        this.durTime = Number(this.encryptData(tempdurTime));
        let temppopNum = JSON.parse(cc.sys.localStorage.getItem("popNum"));
        this.popNum = Number(this.encryptData(temppopNum)); 
 


	}
	
	public saveData(){
        let tempdurTime = this.decryptData(this.durTime.toString());
        cc.sys.localStorage.setItem("durTime",JSON.stringify(tempdurTime));
        
	}
	
	public removeData(key:string){
		cc.sys.localStorage.removeItem(key)	
	}

    private encryptData(data:string){
        let encryptd = data;
        return encryptd;
    }

    private decryptData(data:string){
        let decryptd = data;
        return decryptd;
    }    
}

const dataMgr = DataMgr.getInstance();
export default dataMgr;


