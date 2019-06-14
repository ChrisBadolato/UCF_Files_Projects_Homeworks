#define SIZE 10

struct hotel {
    int rooms[SIZE];
    int available;
};

void init_hotel(struct hotel *h);
void get_room(struct hotel *h);
int find_room(struct hotel *h);

int main () {

    struct hotel plaza;
    int ans;
    init_hotel(&plaza);

    printf("Would you like to check out a room?(y=1,n=0)\n");
    scanf("%d", &ans);

    while(ans == 1) {
    get_room(&plaza);
    printf("Would you like to check out a room?(y=1,n=0)\n");
    scanf("%d", &ans);

    }
    return 0;

}

void init_hotel(struct hotel *h) {
    int i;
    for(i=0; i<SIZE; i++){
        h->rooms[i] = 1;
        h->available = SIZE;

    }

}

void get_room(struct hotel *h) {

    int room_no;

    room_no = find_room(h);

    if (room_no == -1){
        printf("sorry fucking idiot we're full. \n");

    }

    else {
    printf("you will stay in %d. \n", room_no+1);
    h->available--;
    h->rooms[room_no] = 0;
    }


}

int find_room(struct hotel *h) {
    int i;
        for(i=0; i<SIZE; i++) {
            if(h->rooms[i] == 1){
            return i;
            }

        }
        return -1;

}
