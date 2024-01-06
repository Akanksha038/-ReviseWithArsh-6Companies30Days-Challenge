


class DataStream 
{
    private:
    int val=0;
    int counter=0;
    int K=0;
        
public:
    DataStream(int value, int k) {
        val=value;
        counter=0;
        K=k;
        
        
    }
    
    bool consec(int num)
    {
        if(num==val){
            counter++;
            return counter>=K;
        }
        else{
            counter=0;
            return false;
    }
        }
        
    };
    

// /**
//  * Your DataStream object will be instantiated and called as such:
//  * DataStream* obj = new DataStream(value, k);
//  * bool param_1 = obj->consec(num);
//  */






    

