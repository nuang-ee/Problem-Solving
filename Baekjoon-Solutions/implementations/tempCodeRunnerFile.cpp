    cout << "after\n";
    debugPrintPlane(cube, plane, true);
    for (auto e : sides)
        debugPrintPlane(cube, e.first, false);