package worldwanderer.org;

import java.util.Date;
import worldwanderer.org.ServiceOption;

public class PushNotificationService implements ServiceOption {
    
    private String notificationId;
    private String notification;
    private Date date;

    public PhoneController phoneController;

    PushNotificationService(String notificationId, String notification, Date date) {
        this.notificationId = notificationId;
        this.notification = notification;
        this.date = date;
    }

    public Date getDate() {
        return date;
    }

    public String getNotification() {
        return notification;
    }

    public String getNotificationId() {
        return notificationId;
    }

    public boolean sendNotifcation() {
        phoneController.notifcation.popup(this.notification);
        emailService.send(this.notification);
    }
}
