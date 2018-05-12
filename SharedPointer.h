template <typename T>
class SharedPointer {
	T* pointer;
	int *referencesCount;

	inline void DecrementCount() {
		(*referencesCount)--;
	}

	inline void IncrementCount() {
		(*referencesCount)++;
	}
public:
	SharedPointer(T* _pointer) {
		pointer = _pointer;
		referencesCount = new int(1);
	}

	~SharedPointer() {
		if (referencesCount == nullptr)
			return;
		DecrementCount();
		if (*referencesCount == 0) {
			delete pointer;
			delete referencesCount;
		}
	}

	SharedPointer(const SharedPointer<T>& other) {
		pointer = other.pointer;
		referencesCount = other.referencesCount;
		IncrementCount();
	}
	SharedPointer<T>& operator=(const SharedPointer<T>& other) {
		pointer = other.pointer;
		referencesCount = other.referencesCount;
		IncrementCount();
		return *this;
	}

	int UseCount() const {
		if (referencesCount != nullptr)
			return *referencesCount;
		return 0;
	}

	void Reset() {
		if (referencesCount == nullptr)
			return;
		DecrementCount();
		if (*referencesCount == 0) {
			delete pointer;
			delete referencesCount;
		}
		referencesCount = nullptr;
		pointer = nullptr;
	}

	T* operator*() {
		return pointer;
	}

	T* operator ->() {
		return pointer;
	}
};