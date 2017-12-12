import Tkinter as tk
from datetime import datetime as dt
import math
def getCurrentTime():
    cur_hr  = dt.now().hour
    cur_min = dt.now().minute
    cur_sec = dt.now().second
    return (cur_hr, cur_min, cur_sec)
    
def update(): 
    crcl = cnvs.create_oval(rootx-radius3, rooty-radius3, rootx+radius3, rooty+radius3, fill="Black")
    (cur_hr, cur_min, cur_sec) = getCurrentTime()
    theta_hr = (cur_hr*30 - 90)%360 + cur_min*0.5
    theta_hr_rad = (theta_hr*math.pi)/180
    radius_hr = radius3*0.4
    x_hr = rootx + radius_hr*math.cos(theta_hr_rad)
    y_hr = rooty + radius_hr*math.sin(theta_hr_rad)
    theta_min = ((cur_min*6) - 90)%360
    theta_min_rad = (theta_min*math.pi)/180
    radius_min = radius3*0.8
    x_min = rootx + radius_min*math.cos(theta_min_rad)
    y_min = rooty + radius_min*math.sin(theta_min_rad)
    theta_sec = ((cur_sec*6) - 90)%360
    theta_sec_rad = (theta_sec*math.pi)/180
    radius_sec = radius3*0.9
    x_sec = rootx + radius_sec*math.cos(theta_sec_rad)
    y_sec = rooty + radius_sec*math.sin(theta_sec_rad)
    cnvs.create_line(rootx, rooty, x_hr, y_hr, fill="red", width="3")
    cnvs.create_line(rootx, rooty, x_min, y_min, fill="green", width="2")
    cnvs.create_line(rootx, rooty, x_sec, y_sec, fill="white", width="1", smooth="true")
    root.after(1000, update)

if __name__=="__main__":
    width = 400
    height = 400
    radius1 = min(width, height)*0.4
    radius2 = radius1*0.9
    radius3 = radius1*0.85
    rootx = width/2
    rooty = height/2
    root = tk.Tk()
    root.title("CLOCK")
    cnvs = tk.Canvas(root, width="400", height="400")
    crcl = cnvs.create_oval(rootx-radius2, rooty-radius2, rootx+radius2, rooty+radius2, fill="green")
    for theta in range(0, 360, 6):
        #print ("theta : ", theta)
        theta_rad = (theta * math.pi )/180
        x_cord = rootx + radius2 * math.cos(theta_rad)        
        y_cord = rooty + radius2 * math.sin(theta_rad)        
        x_cord_text = rootx + radius1 * math.cos(theta_rad)        
        y_cord_text = rooty + radius1 * math.sin(theta_rad)        
        if theta%30 is 0:
            if(((theta+90)/30)%12 is 0):
                cnvs.create_text(x_cord_text, y_cord_text, text=str("12"))
            else: 
                cnvs.create_text(x_cord_text, y_cord_text, text=str(((theta+90)/30)%12))
            cnvs.create_line(rootx, rooty, x_cord, y_cord, fill="red", width="5")
        else:
            cnvs.create_line(rootx, rooty, x_cord, y_cord, fill="blue", width="2")
            
    update()
    cnvs.pack()
    root.mainloop()
