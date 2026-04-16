#include <bits/stdc++.h>
using namespace std;

class Task {
    std::string name;
public:
    Task(std::string n) : name(n) { 
        std::cout << "  [Created] Task: " << name << "\n"; 
    }
    ~Task() { 
        std::cout << "  [Destroyed] Task: " << name << "\n"; 
    }
    void run() { 
        std::cout << "  -> Running " << name << "...\n"; 
    }
};

void process_task(std::unique_ptr<Task> t) {
    std::cout << "Inside process_task function:\n";
    t->run();
    std::cout << "Exiting process_task function (Task will die here)...\n";
}

struct Resource {
	string name;
	int size_mb;

	Resource(string n, int s): name(n), size_mb(s) {
		cout << "Allocating " << name << endl;
	}
	Resource(const Resource& other) : name(other.name), size_mb(other.size_mb) {
        std::cout << "Copying " << name << " to Heap\n";
    }
	~Resource() {
		cout << "Freeing " << name << endl;
	}
	void print_info() const {
		cout << "Resource " << name << " (" << size_mb << ") MB" << endl;
	}
};

template <typename T>
class AssetManager {
private:
	// map string ID to shared pointer of type T
	unordered_map<string, shared_ptr<T>> storage;

public:
	// takes ownership of new resource
	void load(const string& key, const T& obj) {
		storage[key] = make_shared<T>(obj); // creates the object and the control block efficiently.

	}

	std::optional<shared_ptr<T>> get(const string& key) {
		auto it = storage.find(key);
		if(it != storage.end()) {
			return it->second; // return the existing shared ptr
		}
		return nullopt; // explicitly stating nothing found.
	}

	void show_status() {
		cout << "------- Manager status -------" << endl;
		for (const auto& [key, ptr]: storage) {
			cout << "Key: " << key << " | Ref count: " << ptr.use_count() << endl;
		}
		cout << "------------------------" << endl;
	}
};

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    AssetManager<Resource> manager;

    cout << "Loading resources..." << endl;
    manager.load("player_tex", Resource("PlayerTexture.png", 50));
    manager.load("enemy_tex", Resource("EnemyTexture.png", 20));

    string query = "player_tex";
    cout << "Requesting " << query << endl;

    optional<shared_ptr<Resource>> res = manager.get(query);

    if(res.has_value()) {
    	cout << "Found! " << endl;
    	(*res)->print_info();

    	// prove it's shared
    	manager.show_status();
    } else {
    	cout << "Could not find the resource: " << query << endl;
    }

    query = "background_music";
    cout << "Requesting: " << query << endl;

    auto missing_res = manager.get(query);

    if(!missing_res) {
    	cout << "Safe failure: Resource: " << query << " is missing (nullopt)" << endl;
    }

    {
    	cout << "Creating a temporary owner scope" << endl;
    	shared_ptr<Resource> local_ptr = manager.get("enemy_tex").value();
    	manager.show_status();
    }

    cout << "Left temporary scope" << endl;
    manager.show_status();

    cout << "---------------------------" << endl;

    std::cout << "1. Creating unique_ptr 'task1'...\n";
    std::unique_ptr<Task> task1 = std::make_unique<Task>("Backup Data");

    task1->run();

    // ---------------------------------------------------------
    // 3. Moving Ownership
    // ---------------------------------------------------------
    std::cout << "\n2. Moving ownership from 'task1' to 'task2'...\n";
    std::unique_ptr<Task> task2 = std::move(task1);

    if (task1 == nullptr) {
        std::cout << "  (task1 is now empty/null)\n";
    }
    if (task2 != nullptr) {
        std::cout << "  (task2 now owns the object)\n";
        task2->run();
    }

    // ---------------------------------------------------------
    // 4. Passing to a Function
    // ---------------------------------------------------------
    std::cout << "\n3. Moving 'task2' into a function...\n";
    process_task(std::move(task2));

    std::cout << "\n4. Back in main (task2 is now empty)...\n";

    return 0;


}