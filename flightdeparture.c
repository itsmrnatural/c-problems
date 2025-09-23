#include <stdio.h>
#include <stdlib.h>

void formatTime(int minutes, int *hours, int *mins, char *meridian) {
    // Convert minutes since midnight to 12-hour format
    *hours = minutes / 60;
    *mins = minutes % 60;

    if (*hours == 0) {
        *hours = 12;
        *meridian = 'a';
    } else if (*hours == 12) {
        *meridian = 'p';
    } else if (*hours > 12) {
        *hours -= 12;
        *meridian = 'p';
    } else {
        *meridian = 'a';
    }
}

int main(void) {
    int departures[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrivals[8] = {616, 712, 793, 900, 968, 1075, 1220, 1438};

    int hours, mins;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &mins);

    int user_time = (hours * 60) + mins;

    int closest_index = 0;
    int min_delta = abs(departures[0] - user_time);

    for (int i = 1; i < 8; i++) {
        int d = abs(departures[i] - user_time);
        if (d < min_delta) {
            min_delta = d;
            closest_index = i;
        }
    }

    // Format and display results
    int dep_hours, dep_mins, arrv_hours, arrv_mins;
    char dep_meridian, arrv_meridian;

    formatTime(departures[closest_index], &dep_hours, &dep_mins, &dep_meridian);
    formatTime(arrivals[closest_index], &arrv_hours, &arrv_mins, &arrv_meridian);

    printf(
        "Closest departure time is %02d:%02d %c.m., arriving at %02d:%02d %c.m.\n",
        dep_hours, dep_mins, dep_meridian, arrv_hours, arrv_mins, arrv_meridian
    );

    return 0;
}
