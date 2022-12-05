class OrderedStream {
public:
    vector<long> store;
    int start;
    OrderedStream(int n) {
        store.resize(n+1);
        start=1;
    }
    
    vector<string> insert(int idKey, string value) {
        long convertedValue=0;
        for(int i=4;i>=0;i--){
            convertedValue=convertedValue*100 + (value[i] - 'a' + 1);
        }
        store[idKey]=convertedValue;
        string convertedString;
        vector<string> result;
        while(start < store.size() && store[start]!=0){
            convertedString="";
            for(int i=0;i<5;i++){
                convertedString.push_back((char)(store[start]%100 - 1 + 'a' ));
                store[start]=store[start]/100;
            }
            result.push_back(convertedString);
            start++;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
