

export class Global {

    public static shortNum(count: number){
        let str = "";
        if(count < 10000){
            str = count.toString();
        }else{     
            str = (count/10000).toFixed(2).slice(0,-1) + "w";
        }
        return str;
    }

    public static calculateYear(durSecond: number){
        
        let month = durSecond%12;
        let year = (durSecond - month)/12;

        let date = "";
        if(year <= 0){
            date = month + "月";
        }else{
            if(month <= 0){
                date = year + "年";  
            }  
            else 
            {       
                date = year + "年" + month + "月";
            }
        }
        return date;
    }
    

}