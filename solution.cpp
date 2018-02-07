class Column {
  public:
      int key;
      string value;
      Column(int key, string value) {
          this->key = key;
          this->value = value;
     }
};

class MiniCassandra {
private:
    struct Cmp {  
        //typedef void is_transparent;
        bool operator()(const Column& lhs, const Column& rhs) {
            return lhs.key < rhs.key;
        }
        
        bool operator()(const Column& lhs, const int colId) {
            return lhs.key < colId;
        }
        
        bool operator()(const int colId, const Column& lhs) {
            return colId < lhs.key;
        }
    };
    unordered_map<string, set<Column, Cmp>> store;
    
public:
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param raw_key: a string
     * @param column_key: An integer
     * @param column_value: a string
     * @return: nothing
     */
    void insert(const string &raw_key, int column_key, const string &column_value) {
        // write your code here 
        store[raw_key].insert(Column(column_key, column_value));
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(const string &raw_key, int column_start, int column_end) {
        // write your code here
        if (store.count(raw_key)==0) {
            return vector<Column>();
        }
        auto& cols = store[raw_key];
        auto lit = lower_bound(cols.begin(), cols.end(), column_start, Cmp());
        auto rit = upper_bound(cols.begin(), cols.end(), column_end, Cmp());
        
        vector<Column> results;
        for (; lit != rit; ++lit) {
            results.push_back(*lit);
        }
        return results;
    }
};