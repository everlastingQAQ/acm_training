	//向左找
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    cout << l << '\n';

    //向右找
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << r << '\n';
