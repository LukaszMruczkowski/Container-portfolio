#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

//Class representing any optical device
class optical_device {
public:
	double zoom;
	int weight;
	optical_device* next;
	double zoom_getter() { return zoom; }
	int weight_getter() { return weight; }
	void zoom_setter(double z) { zoom = z; }
	void weight_setter(int w) { weight = w; }
	virtual void print();
	optical_device() : zoom(0.0), weight(0), next(nullptr) {}
	optical_device(double z, int w) : zoom(z), weight(w), next(nullptr) {}
	optical_device(const optical_device& other) : zoom(other.zoom), weight(other.weight), next(nullptr) {}
	~optical_device() { delete next; }
};

void optical_device::print() {
	cout << "Atributes of optical device: \n";
	cout << "Zoom: " << zoom << endl;
	cout << "Weight: " << weight << endl;
}
//Derived class which narrows the concept of optical device
class camera : public optical_device {
public:
	int battery_life;
	string video_format;
	int battery_life_getter() { return battery_life; }
	string format_getter() { return video_format; }
	void battery_life_setter(int b_life);
	void format_setter(string format);
	void print() override;
	camera() : optical_device(), battery_life(1), video_format("MPEG-2") {}
	camera(int b_life, string format, double z, int w) : optical_device(z, w) { format_setter(format); battery_life_setter(b_life); }
	camera(const camera& other) : optical_device(other), battery_life(other.battery_life), video_format(other.video_format) {}
	//Operator overload to check if cameras are the same
	bool operator==(const camera& right)
	{
		bool is_equal = false;
		if (weight == right.weight && zoom == right.zoom && battery_life == right.battery_life && video_format == right.video_format) {
			is_equal = true;
		}
		return is_equal;
	}
};

void camera::print() {
	optical_device::print();
	cout << "Battery life: " << battery_life << endl;
	cout << "Video format: " << video_format << endl << endl;
}

void camera::battery_life_setter(int b_life) {
	if (b_life > 0) {
		battery_life = b_life;
	}
	else {
		cout << "Entered data format is invalid\n";
	}
}

void camera::format_setter(string format) {
	if (format == "MPEG-2" || format == "MPEG-4" || format == "AVCHD" || format == "HDV") {
		video_format = format;
	}
	else {
		cout << "Entered data format is invalid\n";
	}
}
//Class representing a container which is also a template so it's universal
template <class T>
class unique_collection
{
	struct Node {
		T data;
		Node* next;
	};
public:	
	Node* head;
	unique_collection(): head(nullptr) {}
	~unique_collection() { delete head; }
	void insert(T* dod);
	void remove(T* usun);
	void show();
};

//Prints to console all members of the container
template <class T>
void unique_collection<T>::show()
{
	Node* currentNode = head;
	while (currentNode != nullptr) {
		currentNode->data.print();
		currentNode = currentNode->next;
	}
}
//Inserts at the end of the list new node
template <class T>
void unique_collection<T>::insert(T* dod)
{
	Node* currentNode = head;
	if (head == nullptr) {
		head = new Node;
		head->next = nullptr;
		head->data = (*dod);
	}
	else
	{
		while (currentNode->next != nullptr) {
			if (currentNode->data == (*dod)) {
				return;
			}
			currentNode = currentNode->next;
		}
		currentNode->next = new Node;
		currentNode = currentNode->next;
		currentNode->data = (*dod);
		currentNode->next = nullptr;
	}
}
//Removes desired node from the container
template <class T>
void unique_collection<T>::remove(T* usun)
{
	Node* prevNode = nullptr;
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == (*usun)) {
			Node* temp = currentNode;
			if (currentNode == head) {
				head = currentNode->next;
			}
			if (prevNode != nullptr) {
				prevNode->next = currentNode->next;
				currentNode = currentNode->next;
			}
			temp->next = nullptr;
			delete temp;
			return;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
}


int main()
{
	unique_collection<camera>* container = new unique_collection<camera>();
	camera A1, A2(5,"MPEG-2", 4.5, 189), A3(8, "MPEG-4", 7.5, 245);
	container->insert(&A1);
	container->insert(&A2);
	container->insert(&A3);
	cout << "Before deleting\n";
	container->show();
	container->remove(&A2);
	cout << "After deleting\n";
	container->show();
	delete container;
	system("pause");
	return 0;
}

