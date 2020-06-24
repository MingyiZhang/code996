package restoreIpAddress;

import java.util.ArrayList;
import java.util.List;

public class solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ipAddresses = new ArrayList<>();
        String prefix = "";
        getIpAddress(ipAddresses, s, prefix, 0);
        return ipAddresses;
    }

    private void getIpAddress(List<String> ipAddresses, String rest, String prefix, int count) {
        if (count == 4 || rest.isEmpty()) {
            if (count == 4 && rest.isEmpty()) {
                ipAddresses.add(new String(prefix));
            }
            return;
        }
        for (int i = 0; i < Math.min(rest.length(), 3); i++) {
            if (i != 0 && rest.charAt(0) == '0') {
                break;
            }
            String part = rest.substring(0, i + 1);
            if (Integer.parseInt(part) <= 255) {
                if (!prefix.isEmpty()) {
                    part = String.format(".%s", part);
                }
                getIpAddress(ipAddresses, rest.substring(i + 1), String.format("%s%s", prefix, part), count + 1);
            }
        }
    }
}