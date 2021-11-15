// Level:境界等级, StateName:境界名称, UpExp:突破所需修为

export default class LevelCFG {
  private static data =
      {"1":{"Level":1,"StateName":"练气一阶","UpExp":1000}

      ,"2":{"Level":2,"StateName":"","UpExp":1001}

      ,"3":{"Level":3,"StateName":"","UpExp":1002}

      ,"4":{"Level":4,"StateName":"","UpExp":1003}

      ,"5":{"Level":5,"StateName":"","UpExp":1004}

      ,"6":{"Level":6,"StateName":"","UpExp":1005}

      ,"7":{"Level":7,"StateName":"","UpExp":1006}

      ,"8":{"Level":8,"StateName":"","UpExp":1007}

      ,"9":{"Level":9,"StateName":"","UpExp":1008}

      ,"10":{"Level":10,"StateName":"","UpExp":1009}

      ,"11":{"Level":11,"StateName":"","UpExp":1010}

      ,"12":{"Level":12,"StateName":"","UpExp":1011}

      ,"13":{"Level":13,"StateName":"","UpExp":1012}

      ,"14":{"Level":14,"StateName":"","UpExp":1013}

      ,"15":{"Level":15,"StateName":"","UpExp":1014}

      ,"16":{"Level":16,"StateName":"","UpExp":1015}

      ,"17":{"Level":17,"StateName":"","UpExp":1016}

      ,"18":{"Level":18,"StateName":"","UpExp":1017}

      ,"19":{"Level":19,"StateName":"","UpExp":1018}

      ,"20":{"Level":20,"StateName":"","UpExp":1019}

      ,"21":{"Level":21,"StateName":"","UpExp":1020}

      ,"22":{"Level":22,"StateName":"","UpExp":1021}

      ,"23":{"Level":23,"StateName":"","UpExp":1022}

      ,"24":{"Level":24,"StateName":"","UpExp":1023}

      ,"25":{"Level":25,"StateName":"","UpExp":1024}

      ,"26":{"Level":26,"StateName":"","UpExp":1025}

      ,"27":{"Level":27,"StateName":"","UpExp":1026}

      ,"28":{"Level":28,"StateName":"","UpExp":1027}

      ,"29":{"Level":29,"StateName":"","UpExp":1028}

      ,"30":{"Level":30,"StateName":"","UpExp":1029}

      ,"31":{"Level":31,"StateName":"","UpExp":1030}

      ,"32":{"Level":32,"StateName":"","UpExp":1031}

      ,"33":{"Level":33,"StateName":"","UpExp":1032}

      ,"34":{"Level":34,"StateName":"","UpExp":1033}

      ,"35":{"Level":35,"StateName":"","UpExp":1034}

      }// Level:境界等级, StateName:境界名称, UpExp:突破所需修为


    static getData(key: any): any {
        if (key == null || key == undefined)
            return null;
        return this.data[key];
    }

    static getAllData(): any {
        return this.data;
    }

}