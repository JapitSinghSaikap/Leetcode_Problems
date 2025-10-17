class ExamTracker {
public:
    vector<pair<int,long long>> prefixArr;

    void record(int time, int score) {
        long long total = score;
        if(!prefixArr.empty()) total += prefixArr.back().second;
        prefixArr.push_back({time, total});
    }

    long long totalScore(int startTime, int endTime) {
        auto itEnd = upper_bound(prefixArr.begin(), prefixArr.end(), endTime,
                                 [](int t, const pair<int,long long>& p){ return t < p.first; });
        long long sumEnd = 0;
        if(itEnd != prefixArr.begin()) --itEnd, sumEnd = itEnd->second;

        auto itStart = lower_bound(prefixArr.begin(), prefixArr.end(), startTime,
                                   [](const pair<int,long long>& p, int t){ return p.first < t; });
        long long sumStart = 0;
        if(itStart != prefixArr.begin()) --itStart, sumStart = itStart->second;

        return sumEnd - sumStart;
    }
};
