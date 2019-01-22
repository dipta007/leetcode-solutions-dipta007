// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int val;
    int flg;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    flg = 0;
        val = -1;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(flg) return val;
        flg = 1;
        val = Iterator::next();
        return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(flg) {
            flg = 0;
            return val;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if(flg) return true;
        return Iterator::hasNext();
	}
};