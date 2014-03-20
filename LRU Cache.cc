class LRUCache{
public:

	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		unordered_map<int, list<pair<int,int> >::iterator>::iterator it = m_Key2It.find(key);
		if (it==m_Key2It.end())return -1;
		list<pair<int,int> >::iterator Fitrator = it->second;
		int value = Fitrator->second;
		m_Value.splice(m_Value.begin(),m_Value,Fitrator);
		m_Key2It[key] = m_Value.begin();
		return value;
	}

	void set(int key, int value) {
		unordered_map<int,list<pair<int,int> >::iterator>::iterator it = m_Key2It.find(key);
		if (it==m_Key2It.end()){
			if (m_Value.size()==capacity){
				m_Key2It.erase(m_Value.back().first);
				m_Value.pop_back();
			}
			m_Value.insert(m_Value.begin(),make_pair(key,value));
			m_Key2It[key] = m_Value.begin();
		}else{
			list< pair<int,int> >::iterator Fiterator = it->second;
			Fiterator->second = value;
			m_Value.splice(m_Value.begin(),m_Value,Fiterator);
			m_Key2It[key] = m_Value.begin();
		}

		
	}
private:
	int capacity;
	list< pair<int, int> > m_Value;
	unordered_map<int,list< pair<int,int> >::iterator>  m_Key2It;

};
